// HOW TO USE THE PUSH BUTTON

int i = 0;

//First, let's define where the button is

#define button_1 8

//now, on setup function, let's especify how the button works

bool change ();

void setup () {
    pinMode(button_1, INPUT_PULLUP);
    Serial.begin (9600);

    // in this case, when button is off, the arduino will read as on, the oposity is also true
}

//let's use, look the  change function after the loop function to understand

void loop (){
   
    if change () {
	i++;
	Serial.print (i)
    }else{
	none;
    }

}


bool change ():
    //to know the state of the button we must call a variable and set it to the digitalRead of the button port
    x = digitalRead(button_1);
    
    if (x){
	return TRUE;
    }else{
	return FALSE;
    }
}