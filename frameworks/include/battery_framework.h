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

#ifndef BATTERY_FRAMEWORK_H
#define BATTERY_FRAMEWORK_H

#include <iunknown.h> 
#include <samgr_lite.h> 
#include "battery_mgr.h"
#include "battery_info.h"
#include "batterymgr_intf_define.h"
#include "hilog_wrapper.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

static  inline IUnknown *GetBatteryIUnknown(void)
{
	IUnknown *iUnknown = SAMGR_GetInstance()->GetFeatureApi(BATTERY_SERVICE ,BATTERY_INNER);
    if (iUnknown == NULL) {
        POWER_HILOGE("[SERVICE:%s]:BatteryClient::ChargingApiGet iUnknown is null",BATTERY_SERVICE);
        return NULL;
    }
	return iUnknown;
}

int32_t GetBatSoc();
BatteryChargeState GetChargingStatus();
BatteryHealthState GetHealthStatus();
BatteryPluggedType GetPluggedType();
int32_t GetBatVoltage();
char* GetBatTechnology();
int32_t GetBatTemperature();


#ifdef __cplusplus
}
#endif // __cplusplus


#endif