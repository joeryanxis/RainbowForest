/* 
// This file is subject to the terms and conditions defined in
// file 'LICENSE.md', which is part of this source code package.
*/

void detectAndTransmit(SensorNode* node, size_t idx, void* args){
  bool force_update = *((bool*)args);

  node->read();
  
  rgb_f_t rgb;
  rgb.r = rgbElemByUI16(node->getRed());
  rgb.g = rgbElemByUI16(node->getGreen());
  rgb.b = rgbElemByUI16(node->getBlue());

  prev_staff[0][idx] = staff[0][idx]; // store last staff value
  
  size_t val;
  if(COLOR_DETECT_OK == detectedColor(&rgb, &val)){
    detection_ok_staff[0][idx] = true;
    staff[0][idx] = (staff_data_t)val;
    if((staff[0][idx] != prev_staff[0][idx]) || (force_update)){
      sendRV(idx, staff[0][idx]);
    }
  }else{
    detection_ok_staff[0][idx] = false;
  }

  delay(esp_random() & (uint32_t)0x0000003F);
}

void printInfo(SensorNode* node, size_t idx, void* args){
  bool force_update = *((bool*)args);
  
  DEBUG_PORT.print(idx);
  DEBUG_PORT.print(": ");

  if(detection_ok_staff[0][idx]){
    if((staff[0][idx] != prev_staff[0][idx]) || (force_update)){
      DEBUG_PORT.print("(X) ");
      if(force_update){
        DEBUG_PORT.print("(F) ");
      }
    }
    DEBUG_PORT.print(detectable_colors[staff[0][idx]].name);
  }else{
    DEBUG_PORT.print("unknown");
  }

  DEBUG_PORT.print(", ");
}

void updateSensors( void* args ){

  FastLED.addLeds<WS2811, DATA_PIN, RGB>(sensors.getControl(), sensors.getNumControlElements()); // have to add leds in main sketch before sensors.begin()
  SensorStatus_e retval = sensors.begin();
  DEBUG_PORT.print("sensors.begin() returned: "); DEBUG_PORT.println(retval);

  while(1){
    
    bool was_updated = full_update;
    sensors.forEachRandOrder(detectAndTransmit, &full_update);

    DEBUG_PORT.print("Column: [ ");
    sensors.forEach(printInfo, &full_update);
    DEBUG_PORT.println("]");
    
    if(was_updated){
      full_update = false;
    }
  }
}
