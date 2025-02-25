\mainpage
# Тестовое задание на вакансию стажёра програмиста микроконтроллеров (embedded-разработчика) в компанию «Аквариус»

-----------------------------------------------

## Задача

Сторона A хочет передать стороне Б код от банковской ячейки, состоящий из 6 цифр (например, 748253), используя для этого голубиную почту.
Никто не знает о договоренности А и Б пользоваться голубиной почтой для пересылки кода от ячейки, однако:
    - данный способ не позволяет передавать сообщения длиннее 5 цифр;
    - часть голубей может не долететь до получателя (их могут съесть по пути ястребы), но при благоприятных условиях голуби преодолевают расстояние между А и Б за время не более 1 часа;
    - покупать и обучать голубей очень дорого, поэтому желательно ограничить их число при пересылке кода.

Требуется реализовать ПО (клиент и сервер), демонстрирующее решение данной задачи с учетом следующих требований:
 - язык реализации: C;
 - компилятор: GCC;
 - микроконтроллер: [STM32L433VC](https://www.st.com/en/microcontrollers-microprocessors/stm32l433vc.html);
 - в качестве системы сборки проектов использовать [GNU Make](https://www.gnu.org/software/make/) или [CMake](https://cmake.org/);
 - в качестве системы документирования кода проектов использовать [Doxygen](https://www.doxygen.nl/);
 - обмен данными между клиентом и сервером реализовать через UART;
 - допускается использование сторонних библиотек (находящихся в открытом доступе), не решающих за Вас задачу полностью, при указании ссылки на данную библиотеку и её документацию;
 - к решению задачи приложить описание реализованного алгоритма. Достаточно в виде текстового файла с разметкой [Markdown](https://ru.wikipedia.org/wiki/Markdown);
 - исходные тексты разместить на сервисе [GitFlic](https://gitflic.ru/) или [GitHub](https://github.com/) в виде публичных репозиториев.
 
 -----------------------------------------------------

## Использовалось:
 - язык компиляции: C;
 - компилятор [GCC](https://web.archive.org/web/20220423132709/https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads);
 - микроконтроллер [STM32L433VCI3](https://www.st.com/en/microcontrollers-microprocessors/stm32l433vc.html);
 - программа для предварительной настройки МК и инициализации начального кода [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html);
 - библиотека HAL для STM32L4 ([ссылка](https://disk.yandex.ru/d/r74X5RML0KI0EA/STM32Cube_FW_Library_C_F_G_H_L_MP/STM32L4), [документация](https://www.st.com/resource/en/user_manual/um1884-description-of-stm32l4l4-hal-and-lowlayer-drivers-stmicroelectronics.pdf));
 - система сборки проектов [GNU Make](https://www.gnu.org/software/make/);
 - ПО для программирования и отладки [OpenOCD](https://gnutoolchains.com/arm-eabi/openocd/) (команда make flash);
 - Система документирования [Doxygen](https://www.doxygen.nl/).