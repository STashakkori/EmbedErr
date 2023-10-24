// EmbedErr
// $t@$h   QVLx Labs

#include <iostream>
#include "Error.h"
#include "Errorable.h"
#include "Log.h"

class ExampleClass : public Errorable {};

int main()
{
    Logger log;
    log.clear();

    std::vector<std::shared_ptr<Error>> errors;

    ExampleClass example;
    example.pushError(errors, 3);
    
    for (auto error : errors) {
        error->print();
        error->log();
    }
}
