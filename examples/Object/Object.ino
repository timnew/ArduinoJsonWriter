#include "JsonWriter.h"

JsonWriter serialJsonWriter(&Serial);

void setup() {

  Serial.begin(115200);


}
int i = 0;
void loop() {
  delay(1000);
  i++;
  Serial.println(i);


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
}
