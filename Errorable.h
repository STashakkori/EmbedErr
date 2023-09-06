#ifndef ERRORABLE_H
#define ERRORABLE_H

#include <cstdint>
#include <typeinfo>
#include <vector>
#include "Error.h"
#include "Chron.h"

class Errorable {
public:
    virtual void pushError(std::vector<std::shared_ptr<Error>>& errors,
        uint32_t errorCode) final {
        const std::type_info& typeInfo = typeid(*this);
        std::string objectID = typeInfo.name();
        Chron time;
        std::shared_ptr<Error> error =
            std::make_shared<Error>(errorCode, objectID,
                time.getCurrentTime());
        error->timestamp = time.getCurrentTime();
        errors.emplace_back(error);
    };
};

#endif