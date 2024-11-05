// Prints column headers to csv file
bool printHeader() {

    int fileIndex = 0;
    String newFileName = "datos.csv";
    
    // Check if datos.csv exists (if it exists then the filename is incremented to datos-1.csv or -2 -3 etc.)
    while (SD.exists(newFileName)) {
        fileIndex++;
        newFileName = "datos-" + String(fileIndex) + ".csv";
    }
    
    myFile = SD.open(newFileName, FILE_WRITE);
    
    // Write to the file if it opened correctly
    if (myFile) { 
      
        Serial.println("Successfully opened file on SD card!");
        myFile.println("      ");
        
        //Prints the headers to the SD card file
//        myFile.print("Fecha");  //Date              ********We are removing the date column for now********
//        myFile.print(",      ");
        myFile.print("Tiempo (s)");  //numSeconds
        myFile.print(",      ");
        myFile.print("CO (PPM)");  //CO concentration, ppm
        myFile.print(",      ");
        myFile.print("CO (RAW)");  //Raw CO output
        myFile.print(",      ");
        myFile.print("CO2 (PPM)");    //CO2 concentration, ppm
        myFile.print(",      ");
        myFile.print("CO2 RAW");    //Raw CO2 output
        myFile.print(",      ");
        myFile.print("Materia Particular 2.5um");    //PM concentration,
        myFile.print(",      ");
        myFile.print("Materia Particular 10um");    //PM concentration,
        myFile.print(",      ");
        myFile.println("      ");
        myFile.close();
        Serial.println("Successfully printed header to file on SD card!");
        return true;
    }
    else {
        Serial.println("Failed to open file on SD card");
        return false;
    }
}

// Writes most recent values to the csv file
// The first parameter used to be called DateTime now, which is a DateTime object that is returned by the rtc.now() function. DateTime objects conveniently hold
// day, month, year, hour, minute and second fields. Since our rtc is not keeping time properly, we are replacing it with a simple seconds counter using variable
// numSeconds. I have left the previous code commented out so that you can have the option to see how the rtc is implemented, should you choose to do that.
bool writeToFile(int numSeconds, double CO, double CO_raw, double CO2, double CO2_raw, String pm2_5, String pm10) {
  
    myFile = SD.open(fileName, FILE_WRITE);

    // Write to the file if it opened correctly
    if (myFile) {
      
//        Serial.println("Successfully wrote to file on SD card!");
        
//        // Write Date Day/Month/Year (Custom in Peru)       // this used to be the column called fecha 
//        myFile.print(now.day(), DEC);
//        myFile.print('/');
//        myFile.print(now.month(), DEC);
//        myFile.print('/');
//        myFile.print(now.year(), DEC);
//        myFile.print(",      ");
//
//        // Write Time                                       // this was the column called hora, now changed to tiempo (s)
//        myFile.print(now.hour(), DEC);
//        myFile.print(':');
//        myFile.print(now.minute(), DEC);
//        myFile.print(':');
//        myFile.print(now.second(), DEC);
//        myFile.print(",      ");

        // Write the value of the seconds counter
        myFile.print(numSeconds);
        myFile.print(",      ");

        // Write Measured Concentrations
        myFile.print(CO);         //CO concentration, ppm
        myFile.print(",      ");
        myFile.print(CO_raw);         //Raw CO output
        myFile.print(",      ");
//        Serial.print("CO2_raw: ");
//        Serial.println(CO2_raw, DEC);
        myFile.print(CO2);        //CO2 concentration, ppm
        myFile.print(",      ");
        myFile.print(CO2_raw);        //Raw CO2 output
        myFile.print(",      ");
        myFile.print(pm2_5);      //PM 2.5um concentration,
        myFile.print(",      ");
        myFile.print(pm10);       //PM 10um concentration,
        myFile.print(",      ");
//        myFile.print(",      "); //I think this is an old thing as well that we don't need anymore
        myFile.println("      ");
        myFile.close();
        
//        Serial.println("Successfully written data to file on SD card!");
        return true;
    }
    else {
        Serial.println("Failed to open file on SD card");
        return false;
    }
}
