#include "JsonWriter.h"

JsonWriter serialJsonWriter(&Serial);

void setup() {

  Serial.begin(115200);
  serialJsonWriter

  .beginDocument()
    .beginObject()
    .property("id", 7)
    .beginObject("name")
            .property("firstName","James")
            .property("lastName","Bond")
        .endObject()
        .beginArray("languages")
            .string("English")
            .string("Russian")
        .endArray()
        .beginArray("gadgets")
            .beginObject()
                .property("name", "Laser watch")
                .property("returned", false)
            .endObject()
            .beginObject()
                .property("name", "Walther PP")
                .property("returned", false)
                .beginArray("calibers")
                    .number(32)
                    .number(380)
                    .number(22)
                .endArray()
            .endObject()
        .endArray()
        .endObject()
    .endDocument();  

}

void loop() {
}
