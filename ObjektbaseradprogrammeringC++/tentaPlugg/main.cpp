/*
class MyInt{
    private:
    int* ptr;
    public:
    MyInt(int num){
        this->ptr = new int(num);
    }
    ~MyInt(){
        delete ptr;
    }
    MyInt& operator=(const MyInt& rhs){
        if(this == &rhs){
            return *this;
        }
        delete ptr;
        this->ptr = new int(*(rhs.ptr));
        return *this;
    }
    void set(int num){
        *(this->ptr) = num;
    }
    int get(){
        return *ptr;
    }
};
*/

class MyString{
    private:
    char* ptr;
    unsigned int len;
    public:
    MyString(const char* charptr, unsigned int length){
        this-> len = length;
        this->ptr = new char[len+1];
        for(unsigned int i = 0; i < len; i++){
            this->ptr[i] = charptr[i];
        }
        this->ptr[len] = '\0';
    }
    ~MyString(){
        delete []ptr;
    }
    MyString& operator=(const MyString& rhs){
        if(this == &rhs){
            return *this;
        }
        delete []ptr;
        this->len = rhs.len;
        this->ptr = new char[len+1];
        for(unsigned int i = 0; i < len; i++){
            this->ptr[i] = rhs.ptr[i];
        }
        this->ptr[len] = '\0';
        return *this;
    }
    void set(char* newcharptr, unsigned int newlength){
        delete []ptr;
        this->len=newlength;
        this->ptr = new char[len+1];
        for(unsigned int i = 0; i < len; i++){
            this->ptr[i] = newcharptr[i];
        }
        ptr[len] = '\0';
    }
    char* get(){
        return ptr;
    }
};

class Car{
    private:
    int model_year;
    std::string model_name;

    public:
    Car(int year, std::string name) : model_year(year), model_name(name){}
    int getYear(){
        return model_year;
    }
    std::string getModel(){
        return model_name;
    }
};
