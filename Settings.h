
/* --------- SETTINGS ---------*/
//#define SENS_PING_FREQ 500  // Частота обновления данных с датчиков мс
//#define MPU_CALLIBRATE 3 // Количество итераций калибровки MPU-6050
#define DELAY_SECOND_ENGINE 10000 // Задержка между запуском 1-й и 2-й ступенями в мс в атоматичесом ржиме
#define DELAY_PARACHUTE 5000 // Задержка между стартом двигателя 2-й ступени и открытием парашюта в мс в атоматичесом ржиме
#define SMOKE_DELAY 90000 // Задержка между стартом 2й ступени и зажиганием дымовой шашки в мс
        
#define Q1 PD2 // пин 1 мосфета
#define Q2 PD3 // пин 2 мосфета
#define Q3 PD4 // пин 3 мосфета
#define Q4 PE4 // пин 4 мосфета
#define BUZZER_PIN PE5 // пин 5 мосфета
#define PGND_EN PB6 // пин 6 мосфета
/* --------- -------- ---------*/

 /*         ------ просто  знайте ------
 * 0 <5> - автоматический / ручной режимы (SwA) 2п
 * 1 <6> - вкл / выкл сигнал на включение пищалки (SwB) 2п
 * 2 <7> - пуск / ничего (авто режим)(SwD) 2п
 * 3 <8> - выкл / вкл экстренный парашют (SwF) 2п
 * 4 <9> - вкл / ничего подтверждение (SwH) 2п бф
 * 5 <10> - ничего / пуск первой / пуск второй ступени (ручной режим) (SwC) 3п
 *  - - - положения - - - в меню пульта SERVO
 * /\  306  верх       (1)
 * ||  1000  середина  (3)
 * \/  1694  низ       (2)
 */ 
 #define SBUS_0   200
 #define SBUS_UP   500
 #define SBUS_MID  1300
 #define SBUS_DOWN 2000
/*
 * Переферия :
 *  BME280     - Давление, температура, влажность воздуха /
 *  MPU9250    - Положение в пространстве
 *  microSD    - Запись бортового журнала и данных полёта /
 *  SBUS       - Дистанционное управление                 |
 *  adress LED - Индикация состояния (ошибок и т.п.)      /
 */
/*   
 * текущее состояние системы (переменная mode)
 * 0 - ничего не произошло
 * 1 - запуск АУ
 * 2 - запуск РУ
 * 3 - запущена 1 ступень РУ
 * 4 - запущена 2 ступень РУ
 * 5 - запущена 1 ступень АУ
 * 6 - запущена 2 ступень АУ
 * 7 - запуск парашюта АУ / завершение программы АУ
 * 8 - экстренная остановка программы / экстренное открытие парашюта
 */







#define MPU9250_ADDRESS 0x68
#define MAG_ADDRESS 0x0C
 
#define GYRO_FULL_SCALE_250_DPS 0x00 
#define GYRO_FULL_SCALE_500_DPS 0x08
#define GYRO_FULL_SCALE_1000_DPS 0x10
#define GYRO_FULL_SCALE_2000_DPS 0x18
 
#define ACC_FULL_SCALE_2_G 0x00 
#define ACC_FULL_SCALE_4_G 0x08
#define ACC_FULL_SCALE_8_G 0x10
#define ACC_FULL_SCALE_16_G 0x18
