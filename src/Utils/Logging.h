bool CheckLogExistence();

bool __overwrite_log__();

// Writes to the log file with the current time. Code does NOT have file existence checking
// make sure you run CheckLogExistence and verify it's true
void WriteToLog(string log);

// completely wipes the log file. 
// does not check if file exists so make sure to check it's existence prior to running it
void ClearLog() ;

