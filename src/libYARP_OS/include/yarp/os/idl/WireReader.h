/*
 * Copyright (C) 2006-2018 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

#ifndef YARP_OS_IDL_WIREREADER_H
#define YARP_OS_IDL_WIREREADER_H

#include <yarp/conf/numeric.h>
#include <yarp/os/NullConnectionReader.h>
#include <yarp/os/NullConnectionWriter.h>
#include <yarp/os/Bottle.h>
#include <yarp/os/Vocab.h>
#include <yarp/os/idl/WireState.h>
#include <yarp/os/idl/WirePortable.h>
#include <yarp/os/idl/WireVocab.h>

#include <string>

namespace yarp {
    namespace os {
        namespace idl {
            class WireReader;
        }
    }
}

/**
 *
 * IDL-friendly connection reader.  Used by YARP IDL tools, not intended
 * for end-user.
 *
 */
class YARP_OS_API yarp::os::idl::WireReader {
public:
    WireReader(ConnectionReader& reader);

    ~WireReader();

    void expectAccept();

    void accept();

    void allowGetMode();

    bool clear();

    void fail();

    bool read(WirePortable& obj);

    bool read(yarp::os::PortReader& obj);

    bool readNested(WirePortable& obj);

    bool readNested(yarp::os::PortReader& obj);

    bool readI16(std::int16_t& x);

    bool readI32(std::int32_t& x);

    bool readI64(std::int64_t& x);

    bool readBool(bool& x);

    bool readByte(std::int8_t& x);

    bool readVocab(std::int32_t& x);

    bool readDouble(double& x);

    int expectInt() {
        std::int32_t x;
        readI32(x);
        return x;
    }

    double expectDouble() {
        double x;
        readDouble(x);
        return x;
    }

    bool readString(std::string& str, bool *is_vocab = nullptr);

    bool readBinary(std::string& str);

    bool readEnum(std::int32_t& x, WireVocab& converter);

    bool readListHeader();

    bool readListHeader(int len);

    bool readListReturn();

    int getLength() const {
        return state->len;
    }

    ConnectionWriter& getWriter();

    bool isValid();

    bool isError();

    std::string readTag();

    void readListBegin(WireState& nstate, std::uint32_t& len);

    void readSetBegin(WireState& nstate, std::uint32_t& len);

    void readMapBegin(WireState& nstate, WireState& nstate2, std::uint32_t& len);

    void readListEnd();

    void readSetEnd();

    void readMapEnd();

    bool noMore();

    bool getMode() const;

    bool getIsVocab() const;

    const std::string& getString() const;

private:
    NullConnectionWriter null_writer;
    ConnectionReader& reader;
    WireState baseState;
    WireState *state;
    bool flush_if_needed;
    bool support_get_mode;
    bool expecting;
    bool get_is_vocab;
    YARP_SUPPRESS_DLL_INTERFACE_WARNING_ARG(std::string) get_string;
    bool get_mode;


    void scanString(std::string& str, bool is_vocab);
};


#endif // YARP_OS_IDL_WIREREADER_H
