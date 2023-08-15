int function (void){
    static int isCalled;
    return ++isCalled;
}