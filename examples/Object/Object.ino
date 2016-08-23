#include "JsonWriter.h"

JsonWriter serialJsonWriter(&Serial);

void setup() {

  Serial.begin(9600);
  serialJsonWriter

  .beginObject()
        .property("Real name","Thomas A. Anderson")
        .property("Hacker name","Neo")
        .property("Entity","The One")
        .property("Height",185)
        .property("isCreatedByArchitect",true)
  .endObject(); 

}

void loop() {
}
