#include "helpers.h"

void ThrowArgError(int n, const char* argType) {
    std::stringstream ss;
    ss << "Expected argument " << n << " to be a " << argType << ".";
    Nan::ThrowTypeError(ss.str().c_str());
}

bool TestArguments(Nan::NAN_METHOD_ARGS_TYPE info, std::initializer_list<ArgType> args) {
    if (info.Length() < args.size()) {
        Nan::ThrowTypeError("Wrong number of arguments.");
        return false;
    }

    int i = 0;
    for (auto arg = args.begin(); arg < args.end(); arg++, i++) {
        switch (*arg) {
        case atNumber:
            if (!info[i]->IsNumber()) {
                ThrowArgError(i, "number");
                return false;
            }
            break;
        case atBuffer:
            if (!info[i]->IsObject()) {
                ThrowArgError(i, "object");
                return false;
            }
            break;
        case atBool:
            if (!info[i]->IsBoolean()) {
                ThrowArgError(i, "boolean");
                return false;
            }
            break;
        }
    }

    return true;
}

char* BufferToPointer(v8::Local<v8::Value> v) {
    return node::Buffer::Data(Nan::To<v8::Object>(v).ToLocalChecked());
}

Cardinal GetCardinal(v8::Local<v8::Value> v) {
    return Nan::To<uint32_t>(v).FromJust();
}

bool GetBool(v8::Local<v8::Value> v) {
    return Nan::To<bool>(v).FromJust();
}

int GetInt(v8::Local<v8::Value> v) {
    return Nan::To<int32_t>(v).FromJust();
}

double GetDouble(v8::Local<v8::Value> v) {
    return Nan::To<double>(v).FromJust();
}

std::string GetString(v8::Local<v8::Value> v) {
    auto context = Nan::GetCurrentContext();
    return *Nan::Utf8String(v->ToString(context).ToLocalChecked());
}