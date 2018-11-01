 // How to use the serial


 // in the setup function we must call the begin of the Serial

void setup (){
    Serial.begin (9600);
}

 //now you we should have something to shoow on Serial, so I will create a variable call x and print it

void loop (){
    int x = 0;
   
    //let's print it:

    Serial.print (x);

    // let's increment x
   
    x++;
    
    //this loop function goes very fast, so let slow it down

    delay (1000);

    // It's done.
}
