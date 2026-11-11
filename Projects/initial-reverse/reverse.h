void errorHandle(int errorNumber);

enum Error
{
    NO_INPUT_FILE,
    TO_MANY_ARGC,
    MALLOC_ERROR,
    SEEK_FAIL,
};

void errorHandle(int errorNumber)
{
    switch (errorNumber)
    {
    case NO_INPUT_FILE:
        puts("error: No input file");
        break;

    case TO_MANY_ARGC:
        puts("error: To many argguments");
        break;

    case MALLOC_ERROR:
        puts("error: malloc falied");
        break;

    case SEEK_FAIL:
        puts("error: seek falied");
        break;
    
    default:
        break;
    }
}