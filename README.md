ft_printf_by_ncliff
------------
**Использование:**
- Для сборки проекта прописать команду ( в папке проекта ) `make` используя терминал
- Файл **libftprintf.a** необходимо скомпилировать вместе с файлом вашего проекта.

**Пример подключения:**
```C
#include "ft_printf.h"

int main (void)
{
 ft_printf(" Hello world! ");
 return (0);
}
```
**Флаги:**
- **-** Выравнивает результат преобразования по левой границе поля.
- **0** Значение добавляет нули.

**Тип преобразования:**
- **d,i** Параметр int преобразует символы в их знаковое десятичное отображение.
- **u,x,X** Параметр unsigned int преобразуется в беззнаковое беззнаковое десятичное (u) или беззнаковое шестнадцатеричное (x и X).
- **c** араметр int преобразуется в unsigned char и выводится как результирующее значение.
- **s** параметр const char * преобразуется в указатель на массив символьного типа (строковый указатель). Символы из массива выводятся до заканчивающего символа.
- **p** Параметр указателя void *, выводящийся в шестнадцатеричном виде.
- **%** Выводит символ '%' без преобразующих параметров.

Так же имеются параметры **ширины** и **точности**.
Проект был создан в стенах **школы 21**. Автор не разрешает использовать ( код / участки кода ) другим участникам школы 21.
