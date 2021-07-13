/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef IBATTERY_SRV_H
#define IBATTERY_SRV_H
#include <stdint.h>
#include  "battery_info.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
#define BATTECHNOLOGY_LEN 64

typedef struct {
    /** 电池电量 */
    uint16 batSoc;
    /** 电池电压 */
    uint16 batVoltage;
    /** 电池温度 */
    uint16 BatTemp;
    /** 电池容量 */
    uint16 batCapacity;
    /** 充电状态 */
    BatteryChargeState chargingStatus;
    /** 连接类型 */
    BatteryPluggedType pluggedType;
    /** 电池类型 */
    char BatTechnology[BATTECHNOLOGY_LEN];
    /** 电池健康状态 */
    BatteryHealthState healthStatus;
} BatInfo;

typedef struct IBattery {

    uint32_t (*GetSoc)();
    BatteryChargeState (*GetChargingStatus)();
    BatteryHealthState (*GetHealthStatus)();
    BatteryPluggedType (*GetPluggedType)();
    uint32_t (*GetVoltage)();
    char* (*GetTechnology)();
    uint32_t (*GetTemperature)();
    int (*TurnOnLed)(int red, int green, int blue);
    int (*TurnOffLed)();
    int (*SetLedColor)(int red, int green, int blue);
    int (*GetLedColor)(int* red, int* green, int* blue);
    void (*ShutDown)();
    void (*UpdateBatInfo)(BatInfo*);

} IBattery;

 const IBattery *NewBatterInterfaceInstance(void);
 const int32 FreeBatterInterfaceInstance(void);

#ifdef __cplusplus
}
#endif
#endif // IBATTERY_SRV_H