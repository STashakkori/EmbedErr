# EmbedErr
Easy object-oriented way to create and handle errors for embedded systems

The way it works is like this:

Error objects hold this information:
```
const uint16_t errorCode;
const std::string objectID;
std::chrono::system_clock::time_point timestamp;
```
Have a vector of Error objecst somewhere upstream in your code:
```
std::vector<std::shared_ptr<Error>> errors;
```
Implement Errorable inteface in class you want to track errors in:
```
class MyClass : public Errorable {
  // Implementation of the class
};
```
Then push errors to that class whenever you want in the code:
```
ExampleClass example;
example.pushError(errors, 3);
```
Write a handler for the errors or for simple testing:
```
for (auto error : errors) {
  error->print();
  error->log();
}
```
And the error can get logged as well using log.h:
```
Error: code: 3
         id: class ExampleClass
       time: 2023-08-31 21:01:07
```
Notice that the errors with automagically know the source of the error with a time stamp.

It is up to the class implementor to know what the error codes mean but there is no chance
of code clashing this way because they organized by the source object. Easy, simple, but kinda
nice right? Hopefully its useful to somebody somewhere

If using pure ANSI C, then you could implement something similar by passing down a pointer to an
integer in every function and then have the caller handle. This keeps your returns open for your
intended use.
