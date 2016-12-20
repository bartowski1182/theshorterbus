#include "defs.h"
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
            
            while(getline(ifs, line))
            {
                char buffer[100];
                snprintf(buffer, sizeof(buffer), "simc/engine/simc armory=%s calculate_scale_factors=1", line.c_str());
                printf("%s\n", buffer);
            }
        }
    }
    return 0;
}
