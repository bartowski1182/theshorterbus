#include "defs.h"

string generateTrinkets(ifstream * input, string name)
{
    string result = "";
    int counter = 0;
    string line = "";
    string * trinkets;
    trinkets = new string[MAX_TRINKETS];
    while(getline(*input, line))
    {
        trinkets[counter] = line;
        counter++;
    }

    int copyCounter = 1;
    
    for(int i = 0; i < counter; i++)
    {
        for(int j = i + 1; j < counter; j++)
        {
            result += string(" copy=\"") + name + "_" + to_string(copyCounter++) + "\" trinket1=" + trinkets[i] + " trinket2=" + trinkets[j];
        }
    }
    delete[] trinkets;
    return result;
}

int main()
{
    string line;
    DIR *dir;
    string directory = "characters/";
    struct dirent *ent;
    if((dir = opendir(directory.c_str())) != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            const string fileName = ent->d_name;
            const string fullFileName = directory + "/" + fileName;
            
            if(fileName[0] == '.')
                continue;
            
            printf("%s\n", fileName.c_str());
            
            ifstream ifs(fullFileName.c_str());
            
            getline(ifs, line);

            string buffer = "";
            buffer = string(SIMC_PATH) + " armory=" + line + " calculate_scale_factors=1 html=" + RESULTS_DIR + fileName + ".html xml=" + RESULTS_DIR + fileName + ".xml";
            
            buffer += generateTrinkets(&ifs, fileName);
            printf("%s\n", buffer.c_str());
            system(buffer.c_str());
        }
    }
    return 0;
}
