// as of september 9th this code has not been tested
// i wrote it on chromebook lol

int CheckLogExistence();

// wipes log clean. should be run on startup everytime
int u__clean_log__();

// Writes to the log file with the current time. Code does NOT have file existence checking
// make sure you run CheckLogExistence and verify it's true
void WriteToLog(string log, int elevation = 1);

