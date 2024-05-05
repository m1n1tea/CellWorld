# Cellworld
### Краткое описание
Простой симулятор естественного отбора c графическим интерфейсом. Симуляция детерменирована и в некоторых частях использует многопоточность. Работает на linux и на windows. 


<img src="/screenshots/create_world.png" alt="Creation of world"/>

<img src="/screenshots/load_world.png" alt="Load world" />

<img src="/screenshots/simulation.png" alt="Simulation"/>


### Краткий функционал
 - Настроить и создать мир.
 - Сохранить и загрузить мир.
 - Продолжить/Остановить симуляцию.
 - Посмотреть информацию о текущем состоянии мира.
 - Набор предустановленных миров, показывающие возможности проекта.

Более подробное описание можно найти в файле cellworld\_full\_description.pdf

## Предварительные требования
- компилятор поддерживающий C++20
- Настроенный vcpkg
- CMake  (минимум 3.22)
- Visual Studio 2022(windows)
- Зависимости для glfw (linux) - https://www.glfw.org/docs/latest/compile_guide.html
- Doxygen для генерации документации (опционально)

## Установка
Установите репозиторий, перейдите в парку репозитория
```sh
git clone https://github.com/m1n1tea/CellWorld
cd CellWorld
```
Установите необходимые библиотеки через vcpkg
```sh
vcpkg install
```
Выбирете пресет релиза (windows\_release или linux\_release) и соберите проект
```sh
cmake --preset <windows_release | linux_release>
cmake --build build --config release
```
Установите результат сборки
```sh
cmake --install build --config release --prefix <путь куда хотите установить проект>
```
Готово. У вас есть исполняемый файл проекта с предустановленными мирами.
