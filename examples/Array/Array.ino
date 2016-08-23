#include "JsonWriter.h"

JsonWriter serialJsonWriter(&Serial);

void setup() {

  Serial.begin(9600);
  serialJsonWriter

  .beginArray()
                .beginObject()
                    .property("name", "alpha")
                .endObject()
                .beginObject()
                    .property("name", "beta")
                    .property("anotherProperty", 12.67)
                .endObject()
                .beginObject()
                    .property("name", "gamma")
                .endObject()
    .endArray(); 	

}


void loop() {
}
