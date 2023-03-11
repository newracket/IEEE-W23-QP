import processing.serial.*;
import osteele.processing.SerialRecord.*;
// initializing variables
Serial serialPort; // name for serial port
String[] lines = new String[]{"0","0","0","0","0","0"};
int[] targets = new int[7];
String numTargets = "0"; // distraction = 1 if you're looking toward screen and 2 if you are looking away
String start = "0";
void setup(){  
    String serialPortName = SerialUtils.findArduinoPort(); // find which serial port arduino is connected to
    serialPort = new Serial(this, serialPortName, 9600); // set serialPort to found port
}
void draw(){
    String[] file = loadStrings("C:/Users/airha/OneDrive/Productivity-Project/input.txt"); //path directory to text file. Must be exact path file may need to update
    // checks if there is a change to whether you are looking away and tells arduino
    start = file[0];
    if(numTargets != file[0]){      
      numTargets = file[0];
      serialPort.write(numTargets);
      delay(2000);
    }
    if(serialPort.available() > 0) {  // If data is available,
      String read = serialPort.readString();  // read and store it to string read
      for (int i = 0; i < 6; i++) {
        if(Integer.parseInt(read) == i+1){
          lines[i] = lines[i] + 1;
        }   
      }
    } 
    else {
      saveStrings("serial_data.txt", lines);//save string to file
    }    
} 
