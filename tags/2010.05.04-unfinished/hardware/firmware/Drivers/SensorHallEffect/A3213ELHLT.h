/*
             Bicycle LED POV
     Copyright (C) Jorge Pinto aka Casainho, 2008.
              
  casainho [at] gmail [dot] com
      www.casainho.net

 Released under the GPL Licence, Version 3       
*/

/* Control the Vcc of sensor hall effect */
#define SENSOR_HALL_EFFECT_VCC_ENABLE		PORTD |= (1<<PD1)
#define SENSOR_HALL_EFFECT_VCC_DISABLE		PORTD &= ~(1<<PD1)
#define SENSOR_HALL_EFFECT_IS_VCC_ENABLE	bit_is_set(PORTD, PD1)
#define SENSOR_HALL_EFFECT_IS_VCC_DISABLE	bit_is_clear(PORTD, PD1)

/* Get status of data output line of sensor hall effect */
#define SENSOR_HALL_EFFECT_IS_SET			bit_is_set(PIND, PD0)
#define SENSOR_HALL_EFFECT_IS_CLEAR			bit_is_clear(PIND, PD0)

/* Functions prototypes */
void SensorHallEffect_Init(void);
