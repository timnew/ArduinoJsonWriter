#include "JsonWriter.h"


void setup() {

  Serial.begin(115200);


}
int i=0;
void loop() {

  Serial.println(i++);
  
  JsonWriter serialJsonWriter(&Serial);
  serialJsonWriter
   .beginDocument()
      .beginObject()
          .property("Real name","Thomas A. Anderson")
          .property("Hacker name","Neo")
          .property("Entity","The One")
          .property("Height", i)
          .property("isCreatedByArchitect",true)
      .endObject()
    .endDocument(); 
  Serial.println();
  delay(1000);
}
