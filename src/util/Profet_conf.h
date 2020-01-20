/*!
 * \file 		Profet_conf.h
 * \name        Profet_conf.h - pin settings for the 24V heighside PROFET(TM) shield
 * \author      Infineon Technologies AG
 * \copyright   2019 Infineon Technologies AG
 * \version     0.1.1
 * \brief 		
 * 
 * 
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
 * following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following
 * disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided with the distribution.
 *
 * Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 * products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef PROFET_CONF_H
#define PROFET_CONF_H

#include "Arduino.h"


#define RIS             1200        //!< IS Resistor in Ohm
#define ADCFACT         819         //!< Factor to get Voltage from ADC result with 12Bit conversion (4095/5V)

#define kilis_btt6020   2950        //!<
#define kilis_btt6030   2240        //!<

#define DEN_0           2           //!<
#define DEN_1           5           //!<
#define DEN_2           9           //!<

#define DSEL_0          21          //!<
#define DSEL_1          6           //!<

#define IS_0            17          //!<
#define IS_1            18          //!<
#define IS_2            19          //!<

#define IN_0_0          20          //!<
#define IN_1_0          3           //!<
#define IN_0_1          4           //!<
#define IN_1_1          7           //!<
#define IN_0_2          8           //!<

#endif