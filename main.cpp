#include <iostream>
#include <list>
#include <string>
#include <random>
#include <ctime>
//1+rand()%100;
class IObserver {
 public:
  virtual ~IObserver(){};
  virtual void Update(int &numero_randomfrom_subject) = 0;
};

class ISubject {
 public:
  virtual ~ISubject(){};
  virtual void Attach(IObserver *observer) = 0;
  virtual void Detach(IObserver *observer) = 0;
  virtual void Notify() = 0;
};



class Subject : public ISubject {
 public:
  virtual ~Subject() {
    std::cout << "Goodbye, I was the Subject.\n";
  }

 
  void Attach(IObserver *observer) override {
    list_observer_.push_back(observer);
  }
  void Detach(IObserver *observer) override {
    list_observer_.remove(observer);
  }
  void Notify() override {
    std::list<IObserver *>::iterator iterator = list_observer_.begin();
    
    while (iterator != list_observer_.end()) {
      (*iterator)->Update(numero_random);
      ++iterator;
    }
  }

  void CrearNumeroRandom() {
	this->numero_random=1+rand()%100;
    Notify();
  }

 private:
  std::list<IObserver *> list_observer_;
  int numero_random;
};

class Observer : public IObserver {
 public:
  Observer(Subject &subject) : subject_(subject) {
    this->subject_.Attach(this);
  }
  virtual ~Observer() {}

  void Update(const int &numero_randomfrom_subject)  {
    numero_randomfrom_subject_ = numero_randomfrom_subject;
  }
  void RemoveMeFromTheList() {
    subject_.Detach(this);
  }

 private:
  Subject &subject_;
  int numero_randomfrom_subject_;
};



void ClientCode() {


}


//************************ PARTE DEL Strategy ************************************
/*
class NumeroPares : public Strategy
{ 
public:
    void get(int n) override {
        int count=0;
        while (count != 5) {
            for (auto i: n) {
                if (i%2==0) count++;
            }
        }
        if (count == 5) cout << "Listo";
        
    } 
    
};






class MultiploDiez : public Strategy
{
public:  
    void get(int n) override {
        
        while (count != 3) {
            for (auto i: n) {
                if (i%10==0) count++;
            }
        }
    }
};

class MultiploVeinte : public Strategy
{
public:  
    void get(int n) override {
        int count=0;
        while (count != 2) {
            for (auto i: n) {
                if (i%25==0) count++;
            }
        }
    }
};
*/




int main() {
	std::cout<<"Se intento hacer combinando los patrones observer y Strategy\n\n\n";
	std::cout<<"El observer no se logro integrar con el Strategy\n\n\n";
	std::cout<<"El Strategy se hizo por separado :(";

  ClientCode();
  return 0;
}
// Un Observado va generando numeros
// Los obsrvers son notificados con el número aleatorio
// E
