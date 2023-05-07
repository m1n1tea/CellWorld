#include "creature/creature.h"
namespace cellworld{







template<typename T>
void swapIndependent(T& a, T& b) noexcept {
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}

void  reverse(float& x)//TODO сделать через memcpy на всём массиве, а не на отдельном элементе
{
    if (x<=1)
        return;
    unsigned int* i = (unsigned int*)&x;
    *i = 0x7EEEEEEE - *i;
}


Genome Creature::generateGenome() {
    std::uniform_real_distribution<float> dis(-4.0f, 4.0f);
    Genome res;
    res.mass= generator_();
    res.mass>>=24; // вес в диапозоне от 0 до 255
    res.mass+=1;
    res.color= generator_();
    res.color|=0x0000ffff; // убираем прозрачность + у всех живых существ синий цвет на 100%
    for (int i = 0; i < res.neuron_network.size(); ++i) {
        res.neuron_network(i)=dis(generator_);
    }
    return res;
}


Creature::Creature(const Genome& genome, const Position& pos):
  state_(alive),creatures_genome_(genome),
  pos_x_(pos.first), pos_y_(pos.second), speed_direction_(0), speed_module_(0), 
  energy_limit_(genome.mass*coeff_[mass_capacity]),
  energy_(genome.mass* coeff_[mass_capacity] * coeff_[starting_energy]),
  input_neurons_(Eigen::MatrixXf::Zero((4 * look_input_count + input_neurons_count), 1)), output_neurons_(Eigen::MatrixXf::Zero(output_neurons_count, 1)) {}

Creature::Creature(float energy, const Position& pos):
  state_(dead), creatures_genome_(energyColor(energy)),
  pos_x_(pos.first), pos_y_(pos.second), speed_direction_(0),
  speed_module_(0), energy_limit_(0), energy_(energy),
  input_neurons_(), output_neurons_() {}

Creature::Creature(): 
  state_(not_exist), creatures_genome_(base_color_),
  pos_x_(0), pos_y_(0), speed_direction_(0),
  speed_module_(0), energy_limit_(0), energy_(energy),
  input_neurons_(), output_neurons_() {}




void Creature::mixGen(float& gen1,const float& gen2) {
    gen1*=(1.0f-coeff_[mutation_strength]);
    gen1+=gen2* coeff_[mutation_strength];
}


unsigned int Creature::mixGen(const unsigned int& gen1, const unsigned int& gen2) {
    return gen1 * (1.0f - coeff_[mutation_strength]) + gen2 * coeff_[mutation_strength];
}

Genome Creature::createGenome(const Genome& ancestor) {
    Genome kids_genome= ancestor;
    if (coeff_[mutation_strength]<=0){
        return kids_genome;
    }
    Genome mutations=generateGenome();
    if (coeff_[mutation_strength] >= 1) {
        return mutations;
    }
    unsigned int kids_red = ((kids_genome.color >> 24) & 0xff);
    unsigned int kids_green = ((kids_genome.color >> 16) & 0xff);
    unsigned int mutation_red = ((mutations.color >> 24) & 0xff);
    unsigned int mutation_green = ((mutations.color >> 16) & 0xff);
    kids_red= mixGen(kids_red, mutation_red);
    kids_red&=0xff;
    kids_green = mixGen(kids_green, mutation_green);
    kids_green &= 0xff;
    kids_genome.color=(kids_red << 24) + (kids_green << 16);
    kids_genome.color |= 0x0000ffff;
       kids_genome.mass = mixGen(kids_genome.mass, mutations.mass);
    for (int i = 0; i < kids_genome.neuron_network.size(); ++i) {
             mixGen(kids_genome.neuron_network(i), mutations.neuron_network(i));
    }
    return kids_genome;
}


void Creature::die() {
    if(state_==alive){
        state_= dead;
        energy_+=creatures_genome_.mass * coeff_[mass_into_energy];
        creatures_genome_.color=energyColor(energy_);
    }
}

void Creature::eat(Creature& victim) {
    energy_+=victim.energy_;
    victim.energy_=0;
}

void Creature::pushDead(Creature victim) {
    if (state_ == not_exist) {
        *this=std::move(victim);
        return;
    }
    energy_ += victim.energy_;
    victim.energy_ = 0;
}

unsigned int Creature::energyColor(int energy) {
    if (energy > 1023)
        energy = 1023;
    if (energy < -1023)
        energy = -1023;
    energy /=8;
    unsigned int color = ((127 - energy) << 24) + ((127 + energy) << 16);
    color |= 0x000000ff;
    return color;
}



void conjoin(Creature& champion, Creature& candidate) {
        
    if (champion.getState() == not_exist) {
        champion=std::move(candidate);
        return;
    } 
    if (candidate.getState() == alive && (champion.getState() == dead || (champion.getMass() * champion.getSpeed() < candidate.getMass() * candidate.getSpeed()))) {
        champion.die();
        candidate.eat(champion);
        champion = std::move(candidate);
        return;
    }
    candidate.die();
    champion.eat(candidate);
}

void Creature::buildIO(){
    if (state_!=alive)
        return;
    input_neurons_ = Eigen::MatrixXf::Zero(input_neurons_count, 1);
    output_neurons_= Eigen::MatrixXf::Zero(output_neurons_count, 1);
}


















void Creature::reverseInput() {
    for (int i = 0; i < input_neurons_.size(); i++) {
        reverse( input_neurons_.coeffRef(i) );
    }
}



void Creature::getInfo() {
        input_neurons_.setZero();
        input_neurons_.coeffRef(pos_x) = pos_x_;
        input_neurons_.coeffRef(pos_y) = pos_y_;
        input_neurons_.coeffRef(speed_module)=speed_module_;
        input_neurons_.coeffRef(energy) = energy_;
        input_neurons_.coeffRef(bias) = 1;
}

void Creature::look(Creature& found, int direction){
    if (direction == up) {
        input_neurons_.coeffRef(direction* look_input_count+input_neurons_count)=getY()-found.getY();
        
    }
    if (direction == down) {
        input_neurons_.coeffRef(direction * look_input_count+ input_neurons_count) = found.getY()-getY();
    }
    if (direction == left) {
        input_neurons_.coeffRef(direction * look_input_count+ input_neurons_count) = getX() - found.getX();
    }
    if (direction == right) {
        input_neurons_.coeffRef(direction * look_input_count+ input_neurons_count) = found.getX() - getX();
    }
    input_neurons_.coeffRef(direction * look_input_count + color_red+ input_neurons_count) = found.getRed();
    input_neurons_.coeffRef(direction * look_input_count + color_green+ input_neurons_count) = found.getGreen();
    input_neurons_.coeffRef(direction * look_input_count + color_blue+ input_neurons_count) = found.getBlue();
}

void Creature::think(){
    output_neurons_.noalias() = creatures_genome_.neuron_network*input_neurons_;
    
}

void Creature::act(){
    if (state_==alive){
        speed_direction_=0;
        if (output_neurons_.coeff(vertical_or_horizontal) > 0) {// <=0 вертикально, >0 горизонтально
            speed_direction_+=2;
        }
        if (output_neurons_.coeff(decrease_or_increase) > 0) {// <=0 уменьшаем, >0 увеличиваем
            ++speed_direction_;
        }
        int actual_speed_change= output_neurons_.coeff(change_speed_module);
        speed_module_+= actual_speed_change;
        if (speed_module_ < 0) {
            actual_speed_change-=speed_module_;
            speed_module_=0;
        }
        energy_-= actual_speed_change * actual_speed_change* coeff_[change_speed_module_cost];
        energy_ -= creatures_genome_.mass * coeff_[mass_cost];
    }
    if (speed_direction_ == up) {
        pos_y_-=speed_module_;
    }
    if (speed_direction_ == right) {
        pos_x_ += speed_module_;
    }
    if (speed_direction_ == down) {
        pos_y_ += speed_module_;
    }
    if (speed_direction_ == left) {
        pos_x_ -= speed_module_;
    }
    speed_module_ -= coeff_[braking_force];
    if (speed_module_ < 0) {
        speed_module_ = 0;
    }
    
    

}

Creature Creature::makeChild(const Position& pos) {
    if (pos==bad_position)
        return Creature();
    Creature child(createGenome(creatures_genome_), pos);
    energy_-=child.creatures_genome_.mass*coeff_[mass_into_energy];
    if (energy_ > 0) {
        energy_/=2.0f;
        child.energy_=energy_;
    }
    else {
        child.energy_=0;
    }
    return child;
}

Creature Creature::makeLeftover() {
    if (energy_<=energy_limit_ || state_==dead)
        return Creature();
    float extra_energy= energy_ - energy_limit_+0.01f;
    energy_=energy_limit_-0.01f;
    return Creature(extra_energy,{getX(), getY()});
}






Position Field::generatePosition() {
    if (size_x_ == 0 || size_y_ == 0) {
        return bad_position;
    }
    std::uniform_int_distribution<int> dis_x(0, size_x_ - 1);
    std::uniform_int_distribution<int> dis_y(0, size_y_ - 1);
    Position res = { dis_x(generator_),dis_y(generator_) };
    int tries=0;
    while (zoo_[res.first * size_y_ + res.second].getState() != not_exist) {
        if (tries == 100) {
            return bad_position;
        }
        res.first= dis_x(generator_);
        res.second = dis_y(generator_);
        ++tries;
    }
    
    return res;
}

Creature& Field::getCreature(const Position& pos) { 
    if (pos!=bad_position)
        return zoo_[pos.first*size_y_+pos.second]; 
    return bad_creature;
}


Position Field::findClosePosition(Creature& ancestor) {
    int x=ancestor.getX();
    int y=ancestor.getY();
    int direction= ancestor.getDirection();

    if (direction == down) {
        if (y!=0){
            if (zoo_[x*size_y_+y-1].getState()!=alive)
                return {x,y-1};
        }
        else{
            if (zoo_[x * size_y_ + size_y_ - 1].getState() != alive)
                return { x,size_y_ - 1 };
        }
    }

    if (direction == up) {
        if (y != size_y_ - 1){
            if (zoo_[x * size_y_ + y + 1].getState() != alive)
                return { x,y + 1 };
        }
        else{
            if (zoo_[x * size_y_].getState() != alive)
                return { x, 0};
        }
    }

    if (direction == right) {
        if (x!=0){
            if (zoo_[(x-1) * size_y_ + y].getState() != alive)
                return { x-1,y };
        }
        else{
            if (zoo_[(size_x_ - 1) * size_y_ + y].getState() != alive)
                return { size_x_ - 1,y };
        }
    }

    if (direction == left) {
        if (x != size_x_ - 1){
            if (zoo_[(x+1) * size_y_ + y].getState() != alive)
                return { x+1,y };
        }
        else{
            if (zoo_[y].getState() != alive)
                return { 0,y };
        }
    }
    
    return bad_position;
}


bool Field::validX(int x) {
    return (x >= 0 &&  x < size_x_);
}

bool Field::validY(int y) {
    return (y >= 0 && y < size_y_);
}

void Field::spawnCreature(const Position& pos){
    if (pos != bad_position)
        zoo_[pos.first * size_y_ + pos.second]=Creature(Creature::generateGenome(), pos);
}

void Field::spawnCreature(Creature child) {
    conjoin(zoo_[child.getX() * size_y_ + child.getY()], child);
}
void Field::spawnFood(float energy, const Position& pos) {
    spawnCreature(Creature(energy,pos));
}




Creature& Field::findCreature(Creature& finder, int direction) {
    int x = finder.getX();
    int y = finder.getY();
    if (direction == up) {
        do{
            --y;
            if (y<0)
                y+=size_y_;
        }while (zoo_[x * size_y_ + y].getState() == not_exist);
            
    }
    if (direction == down) {
        do{
            ++y;
            if (y >= size_y_)
                y -= size_y_;
        }while (zoo_[x * size_y_ + y].getState() == not_exist);
            
    }
    if (direction == left) {
        do{
            --x;
            if (x < 0)
                x += size_x_;
        }while (zoo_[x * size_y_ + y].getState() == not_exist);
    }
    if (direction == right) {
        do{
            ++x;
            if (x >= size_x_)
                x -= size_x_;
        } while (zoo_[x * size_y_ + y].getState() == not_exist);
            
    }
    return zoo_[x * size_y_ + y];
}

void Field::clear() {
    zoo_=std::vector(size_x_ * size_y_, Creature());
    empty_zoo_ = std::vector(size_x_ * size_y_, Creature());
}

void Field::updatePositions(){
//auto start = std::chrono::steady_clock::now();
//auto end = std::chrono::steady_clock::now();
//std::chrono::duration<double> time = end - start;
//std::cout << "\n" << time.count();
    

    for (int i = 0; i < size_; ++i) {
        Creature& current = zoo_[i];
        if (current.getState() == alive){
            current.look(findCreature(current,up), up);
            current.look(findCreature(current, down), down);
            current.look(findCreature(current, left), left);
            current.look(findCreature(current, right), right);
            current.getInfo();
            current.reverseInput();
        }
    }

    
   //#pragma omp parallel for schedule(static, 1)
    for (int i = 0; i < size_; ++i) {
        
        if (zoo_[i].getState() == alive) {
            zoo_[i].think();
        }
    }

    for (int i = 0; i < size_; ++i) {

        if (zoo_[i].getState()== not_exist)
            continue;

        zoo_[i].act();

        if (!validX(zoo_[i].pos_x_)) {
            zoo_[i].pos_x_ %=size_x_;
            if (zoo_[i].pos_x_ <0)
                zoo_[i].pos_x_ +=size_x_;
        }
        if (!validY(zoo_[i].pos_y_)) {
            zoo_[i].pos_y_ %= size_y_;
            if (zoo_[i].pos_y_ < 0)
                zoo_[i].pos_y_ += size_y_;
        }
        
    }






    for (int i = 0; i < size_; ++i) {

        if (zoo_[i].getState() == not_exist)
            continue;


        if (zoo_[i].getEnergy() > zoo_[i].getEnergyLimit()) {
            empty_zoo_[i].pushDead(zoo_[i].makeLeftover());
        }
        conjoin(empty_zoo_[zoo_[i].pos_x_ * size_y_ + zoo_[i].pos_y_], zoo_[i]);

    }



    


    swapIndependent(empty_zoo_,zoo_);
    for (int i = 0; i < size_; ++i)
            empty_zoo_[i].stopExisting();
}

void Field::updateStates(){
    for (int i = 0; i < size_; ++i) {
            Creature& current =zoo_[i];
            if (current.getState() != alive)
                continue;
            if (current.getEnergy()<0) {
                current.die();
                continue;
            }
            if (current.wantToReproduce()) {
                spawnCreature(current.makeChild(findClosePosition(current)));
            }
    }

}


void* Field::createTexture() {

    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    return (void*)texture;
}


void Field::updateTexture() {
    for (int i = 0; i < size_x_; ++i) {
        for (int j = 0; j < size_y_; ++j) {
            colors[j*size_x_+i]=getColor({i,j});
        }
    }
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, size_x_, size_y_, 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, &(colors[0]));
}
void Field::deleteTexture() {
    glBindTexture(GL_TEXTURE_2D, 0);
}



void saveWorld(const char* path, Field* current_field, std::array<float, coefficients_count>* coefficents) {
    std::ofstream safe_file(path, std::ios::binary);
    if (!safe_file) {
        safe_file.close();
        return;
    }
    int x = current_field->sizeX();
    int y = current_field->sizeY();
    int saved=1;
    safe_file << saved << ' ';
    safe_file << x << ' ' << y << ' ';
    char* converted = new char[sizeof(Creature) - 2 * sizeof(Eigen::MatrixXf)];
    for (int i = 0; i < x * y; ++i) {
        Creature& current = (*current_field)[i];
        std::memcpy(converted, &current, sizeof(Creature) - 2*sizeof(Eigen::MatrixXf));
        safe_file.write(converted, sizeof(Creature) - 2*sizeof(Eigen::MatrixXf));
    }
    delete[] converted;
    safe_file << ' ';
    for (int i = 0; i < coefficients_count; ++i) {
        safe_file << (*coefficents)[i] << ' ';
    }
    safe_file << generator_;
    safe_file.close();
}

void loadWorld(const char* path, Field* current_field, std::array<float, coefficients_count>* coefficents) {
    std::ifstream safe_file(path, std::ios::binary);
    if (!safe_file) {
        safe_file.close();
        return;
    }
    int x,y;
    int check;
    safe_file >> check;
    if (check!=1) {
        safe_file.close();
        return;
    }
    safe_file >> x >> y;
    *current_field=Field(x,y);
    char* converted= new char[sizeof(Creature) - 2 * sizeof(Eigen::MatrixXf)];
    safe_file.read(converted, 1);
    for (int i = 0; i < x * y; ++i) {
        Creature& current = (*current_field)[i];
        safe_file.read(converted, sizeof(Creature) - 2*sizeof(Eigen::MatrixXf));
        std::memcpy(&current, converted, sizeof(Creature)-2*sizeof(Eigen::MatrixXf));
        current.buildIO();
    }
    delete[] converted;
    for (int i = 0; i < coefficients_count; ++i) {
        safe_file >> (*coefficents)[i];
    }
    safe_file >> generator_;
    safe_file.close();
}

 bool findFile(const char* path) {
    std::ifstream safe_file(path, std::ios::binary);
    if (!safe_file) {
        safe_file.close();
        return false;
    }
    int check;
    safe_file >> check;
    safe_file.close();
    return (check==1);
}






}


