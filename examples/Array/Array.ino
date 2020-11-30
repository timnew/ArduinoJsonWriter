#include "JsonWriter.h"

JsonWriter serialJsonWriter(&Serial);

void setup() {

  Serial.begin(115200);
	
}

int i = 0;
void loop() {
    delay(1000);
    i++;
    Serial.println();

    serialJsonWriter
    .beginDocument(true, 3)
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
                .property("count", i)
            .endObject()
        .endArray()
    .endDocument(); 
}
