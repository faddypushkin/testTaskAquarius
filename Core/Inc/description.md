\page 1 Настройки в STM32CubeMX:

 - частота системы тактирования МК - 80МГц;
 - для внутреннего прерывания выбран TIM2 с Prescaler - 40 000 (-> счёт раз в 0,5 мс) и Counter Period - 7 200 000 (-> срабатывает раз в час);
 - выбран USART1 c Boud Rate - 9600 Bits/s, Word Length - 8 Bits, Stop Bits - 1;
 - остальные настройки остались в состоянии, которе генерирует CubeMX автоматически.