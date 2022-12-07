/*
* File name   : MQTT.c
* Created     : 04-Dec-2022
* Author      : Dhiraj Bennadi
* Edited By   : Kevin Tom on 5th Dec 2022
* 
*
*
*--------------------------------------------------------------------------
* Copyright 2021 HiveMQ GmbH
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*       http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/


#include <string.h>
#include "MQTTClient.h"
#include "pubsub_opts.h"
#include <stdlib.h>
#include <unistd.h>
#include "MQTT.h"

int main()
{
    int retVal = 0;

    retVal = mqtt_Connect();

    if(retVal != MQTTCLIENT_SUCCESS)
    {
        printf("Client Connection Failed\n");
        return -1;
    }
    else
    {
        printf("Client Connected to Cloud\n");
    }

    const char* topic = "Dhiraj/Level1";
    retVal = mqtt_Subscribe(topic);

    if(retVal != MQTTCLIENT_SUCCESS)
    {
        printf("Client Subscribe Failed\n");
        return -1;
    }
    else
    {
        printf("Client Subscribed to %s", topic);
    }

    while(1)
    {
        sleep(1);
    }

    mqtt_Close_Connection();
    return 0;
}


