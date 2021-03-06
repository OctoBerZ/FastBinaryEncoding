// Automatically generated by the Fast Binary Encoding compiler, do not modify!
// https://github.com/chronoxor/FastBinaryEncoding
// Source: proto.fbe
// Version: 1.3.0.0

#pragma once

#if defined(__clang__)
#pragma clang system_header
#elif defined(__GNUC__)
#pragma GCC system_header
#elif defined(_MSC_VER)
#pragma system_header
#endif

#include "proto_models.h"

namespace FBE {
namespace proto {

// Fast Binary Encoding proto protocol version
struct ProtocolVersion
{
    // Protocol major version
    static const int major = 0;
    // Protocol minor version
    static const int minor = 0;
};

} // namespace proto
} // namespace FBE

namespace FBE {
namespace proto {

// Fast Binary Encoding proto sender
template <class TBuffer>
class Sender : public virtual FBE::Sender<TBuffer>
{
public:
    Sender()
        : OrderMessageModel(this->_buffer)
        , BalanceMessageModel(this->_buffer)
        , AccountMessageModel(this->_buffer)
    {}
    Sender(const Sender&) = default;
    Sender(Sender&&) noexcept = default;
    virtual ~Sender() = default;

    Sender& operator=(const Sender&) = default;
    Sender& operator=(Sender&&) noexcept = default;

    size_t send(const ::proto::OrderMessage& value)
    {
        // Serialize the value into the FBE stream
        size_t serialized = OrderMessageModel.serialize(value);
        assert((serialized > 0) && "proto::OrderMessage serialization failed!");
        assert(OrderMessageModel.verify() && "proto::OrderMessage validation failed!");

        // Log the value
        if (this->_logging)
        {
            std::string message = value.string();
            this->onSendLog(message);
        }

        // Send the serialized value
        return this->send_serialized(serialized);
    }

    size_t send(const ::proto::BalanceMessage& value)
    {
        // Serialize the value into the FBE stream
        size_t serialized = BalanceMessageModel.serialize(value);
        assert((serialized > 0) && "proto::BalanceMessage serialization failed!");
        assert(BalanceMessageModel.verify() && "proto::BalanceMessage validation failed!");

        // Log the value
        if (this->_logging)
        {
            std::string message = value.string();
            this->onSendLog(message);
        }

        // Send the serialized value
        return this->send_serialized(serialized);
    }

    size_t send(const ::proto::AccountMessage& value)
    {
        // Serialize the value into the FBE stream
        size_t serialized = AccountMessageModel.serialize(value);
        assert((serialized > 0) && "proto::AccountMessage serialization failed!");
        assert(AccountMessageModel.verify() && "proto::AccountMessage validation failed!");

        // Log the value
        if (this->_logging)
        {
            std::string message = value.string();
            this->onSendLog(message);
        }

        // Send the serialized value
        return this->send_serialized(serialized);
    }

public:
    // Sender models accessors
    FBE::proto::OrderMessageModel<TBuffer> OrderMessageModel;
    FBE::proto::BalanceMessageModel<TBuffer> BalanceMessageModel;
    FBE::proto::AccountMessageModel<TBuffer> AccountMessageModel;
};

} // namespace proto
} // namespace FBE

namespace FBE {
namespace proto {

// Fast Binary Encoding proto receiver
template <class TBuffer>
class Receiver : public virtual FBE::Receiver<TBuffer>
{
public:
    Receiver() {}
    Receiver(const Receiver&) = default;
    Receiver(Receiver&&) = default;
    virtual ~Receiver() = default;

    Receiver& operator=(const Receiver&) = default;
    Receiver& operator=(Receiver&&) = default;

protected:
    // Receive handlers
    virtual void onReceive(const ::proto::OrderMessage& value) {}
    virtual void onReceive(const ::proto::BalanceMessage& value) {}
    virtual void onReceive(const ::proto::AccountMessage& value) {}

    // Receive message handler
    bool onReceive(size_t type, const void* data, size_t size) override
    {
        switch (type)
        {
            case FBE::proto::OrderMessageModel<ReadBuffer>::fbe_type():
            {
                // Deserialize the value from the FBE stream
                OrderMessageModel.attach(data, size);
                assert(OrderMessageModel.verify() && "proto::OrderMessage validation failed!");
                [[maybe_unused]] size_t deserialized = OrderMessageModel.deserialize(OrderMessageValue);
                assert((deserialized > 0) && "proto::OrderMessage deserialization failed!");

                // Log the value
                if (this->_logging)
                {
                    std::string message = OrderMessageValue.string();
                    this->onReceiveLog(message);
                }

                // Call receive handler with deserialized value
                onReceive(OrderMessageValue);
                return true;
            }
            case FBE::proto::BalanceMessageModel<ReadBuffer>::fbe_type():
            {
                // Deserialize the value from the FBE stream
                BalanceMessageModel.attach(data, size);
                assert(BalanceMessageModel.verify() && "proto::BalanceMessage validation failed!");
                [[maybe_unused]] size_t deserialized = BalanceMessageModel.deserialize(BalanceMessageValue);
                assert((deserialized > 0) && "proto::BalanceMessage deserialization failed!");

                // Log the value
                if (this->_logging)
                {
                    std::string message = BalanceMessageValue.string();
                    this->onReceiveLog(message);
                }

                // Call receive handler with deserialized value
                onReceive(BalanceMessageValue);
                return true;
            }
            case FBE::proto::AccountMessageModel<ReadBuffer>::fbe_type():
            {
                // Deserialize the value from the FBE stream
                AccountMessageModel.attach(data, size);
                assert(AccountMessageModel.verify() && "proto::AccountMessage validation failed!");
                [[maybe_unused]] size_t deserialized = AccountMessageModel.deserialize(AccountMessageValue);
                assert((deserialized > 0) && "proto::AccountMessage deserialization failed!");

                // Log the value
                if (this->_logging)
                {
                    std::string message = AccountMessageValue.string();
                    this->onReceiveLog(message);
                }

                // Call receive handler with deserialized value
                onReceive(AccountMessageValue);
                return true;
            }
            default: break;
        }

        return false;
    }

private:
    // Receiver values accessors
    ::proto::OrderMessage OrderMessageValue;
    ::proto::BalanceMessage BalanceMessageValue;
    ::proto::AccountMessage AccountMessageValue;

    // Receiver models accessors
    FBE::proto::OrderMessageModel<ReadBuffer> OrderMessageModel;
    FBE::proto::BalanceMessageModel<ReadBuffer> BalanceMessageModel;
    FBE::proto::AccountMessageModel<ReadBuffer> AccountMessageModel;
};

} // namespace proto
} // namespace FBE

namespace FBE {
namespace proto {

// Fast Binary Encoding proto proxy
template <class TBuffer>
class Proxy : public virtual FBE::Receiver<TBuffer>
{
public:
    Proxy() {}
    Proxy(const Proxy&) = default;
    Proxy(Proxy&&) = default;
    virtual ~Proxy() = default;

    Proxy& operator=(const Proxy&) = default;
    Proxy& operator=(Proxy&&) = default;

protected:
    // Proxy handlers
    virtual void onProxy(FBE::proto::OrderMessageModel<ReadBuffer>& model, size_t type, const void* data, size_t size) {}
    virtual void onProxy(FBE::proto::BalanceMessageModel<ReadBuffer>& model, size_t type, const void* data, size_t size) {}
    virtual void onProxy(FBE::proto::AccountMessageModel<ReadBuffer>& model, size_t type, const void* data, size_t size) {}

    // Receive message handler
    bool onReceive(size_t type, const void* data, size_t size) override
    {
        switch (type)
        {
            case FBE::proto::OrderMessageModel<ReadBuffer>::fbe_type():
            {
                // Attach the FBE stream to the proxy model
                OrderMessageModel.attach(data, size);
                assert(OrderMessageModel.verify() && "proto::OrderMessage validation failed!");

                size_t fbe_begin = OrderMessageModel.model.get_begin();
                if (fbe_begin == 0)
                    return false;
                // Call proxy handler
                onProxy(OrderMessageModel, type, data, size);
                OrderMessageModel.model.get_end(fbe_begin);
                return true;
            }
            case FBE::proto::BalanceMessageModel<ReadBuffer>::fbe_type():
            {
                // Attach the FBE stream to the proxy model
                BalanceMessageModel.attach(data, size);
                assert(BalanceMessageModel.verify() && "proto::BalanceMessage validation failed!");

                size_t fbe_begin = BalanceMessageModel.model.get_begin();
                if (fbe_begin == 0)
                    return false;
                // Call proxy handler
                onProxy(BalanceMessageModel, type, data, size);
                BalanceMessageModel.model.get_end(fbe_begin);
                return true;
            }
            case FBE::proto::AccountMessageModel<ReadBuffer>::fbe_type():
            {
                // Attach the FBE stream to the proxy model
                AccountMessageModel.attach(data, size);
                assert(AccountMessageModel.verify() && "proto::AccountMessage validation failed!");

                size_t fbe_begin = AccountMessageModel.model.get_begin();
                if (fbe_begin == 0)
                    return false;
                // Call proxy handler
                onProxy(AccountMessageModel, type, data, size);
                AccountMessageModel.model.get_end(fbe_begin);
                return true;
            }
            default: break;
        }

        return false;
    }

private:
    // Proxy models accessors
    FBE::proto::OrderMessageModel<ReadBuffer> OrderMessageModel;
    FBE::proto::BalanceMessageModel<ReadBuffer> BalanceMessageModel;
    FBE::proto::AccountMessageModel<ReadBuffer> AccountMessageModel;
};

} // namespace proto
} // namespace FBE

namespace FBE {
namespace proto {

// Fast Binary Encoding proto client
template <class TBuffer>
class Client : public virtual Sender<TBuffer>, protected virtual Receiver<TBuffer>
{
public:
    Client() = default;
    Client(const Client&) = default;
    Client(Client&&) = default;
    virtual ~Client() = default;

    Client& operator=(const Client&) = default;
    Client& operator=(Client&&) = default;

    // Reset client buffers
    void reset()
    {
        std::scoped_lock locker(this->_lock);
        reset_requests();
    }

    // Watchdog for timeouts
    void watchdog(uint64_t utc)
    {
        std::scoped_lock locker(this->_lock);
        watchdog_requests(utc);
    }

protected:
    std::mutex _lock;
    uint64_t _timestamp{0};

    virtual bool onReceiveResponse(const ::proto::OrderMessage& response) { return false; }
    virtual bool onReceiveResponse(const ::proto::BalanceMessage& response) { return false; }
    virtual bool onReceiveResponse(const ::proto::AccountMessage& response) { return false; }

    virtual bool onReceiveReject(const ::proto::OrderMessage& reject) { return false; }
    virtual bool onReceiveReject(const ::proto::BalanceMessage& reject) { return false; }
    virtual bool onReceiveReject(const ::proto::AccountMessage& reject) { return false; }

    virtual void onReceiveNotify(const ::proto::OrderMessage& notify) {}
    virtual void onReceiveNotify(const ::proto::BalanceMessage& notify) {}
    virtual void onReceiveNotify(const ::proto::AccountMessage& notify) {}

    virtual void onReceive(const ::proto::OrderMessage& value) override { if (!onReceiveResponse(value) && !onReceiveReject(value)) onReceiveNotify(value); }
    virtual void onReceive(const ::proto::BalanceMessage& value) override { if (!onReceiveResponse(value) && !onReceiveReject(value)) onReceiveNotify(value); }
    virtual void onReceive(const ::proto::AccountMessage& value) override { if (!onReceiveResponse(value) && !onReceiveReject(value)) onReceiveNotify(value); }

    // Reset client requests
    virtual void reset_requests()
    {
        Sender<TBuffer>::reset();
        Receiver<TBuffer>::reset();
    }

    // Watchdog client requests for timeouts
    virtual void watchdog_requests(uint64_t utc)
    {
    }
};

} // namespace proto
} // namespace FBE

namespace FBE {
namespace proto {

// Fast Binary Encoding proto final sender
template <class TBuffer>
class FinalSender : public virtual FBE::Sender<TBuffer>
{
public:
    FinalSender()
        : OrderMessageModel(this->_buffer)
        , BalanceMessageModel(this->_buffer)
        , AccountMessageModel(this->_buffer)
    { this->final(true); }
    FinalSender(const FinalSender&) = default;
    FinalSender(FinalSender&&) noexcept = default;
    virtual ~FinalSender() = default;

    FinalSender& operator=(const FinalSender&) = default;
    FinalSender& operator=(FinalSender&&) noexcept = default;

    size_t send(const ::proto::OrderMessage& value)
    {
        // Serialize the value into the FBE stream
        size_t serialized = OrderMessageModel.serialize(value);
        assert((serialized > 0) && "proto::OrderMessage serialization failed!");
        assert(OrderMessageModel.verify() && "proto::OrderMessage validation failed!");

        // Log the value
        if (this->_logging)
        {
            std::string message = value.string();
            this->onSendLog(message);
        }

        // Send the serialized value
        return this->send_serialized(serialized);
    }

    size_t send(const ::proto::BalanceMessage& value)
    {
        // Serialize the value into the FBE stream
        size_t serialized = BalanceMessageModel.serialize(value);
        assert((serialized > 0) && "proto::BalanceMessage serialization failed!");
        assert(BalanceMessageModel.verify() && "proto::BalanceMessage validation failed!");

        // Log the value
        if (this->_logging)
        {
            std::string message = value.string();
            this->onSendLog(message);
        }

        // Send the serialized value
        return this->send_serialized(serialized);
    }

    size_t send(const ::proto::AccountMessage& value)
    {
        // Serialize the value into the FBE stream
        size_t serialized = AccountMessageModel.serialize(value);
        assert((serialized > 0) && "proto::AccountMessage serialization failed!");
        assert(AccountMessageModel.verify() && "proto::AccountMessage validation failed!");

        // Log the value
        if (this->_logging)
        {
            std::string message = value.string();
            this->onSendLog(message);
        }

        // Send the serialized value
        return this->send_serialized(serialized);
    }

public:
    // Sender models accessors
    FBE::proto::OrderMessageFinalModel<TBuffer> OrderMessageModel;
    FBE::proto::BalanceMessageFinalModel<TBuffer> BalanceMessageModel;
    FBE::proto::AccountMessageFinalModel<TBuffer> AccountMessageModel;
};

} // namespace proto
} // namespace FBE

namespace FBE {
namespace proto {

// Fast Binary Encoding proto final receiver
template <class TBuffer>
class FinalReceiver : public virtual FBE::Receiver<TBuffer>
{
public:
    FinalReceiver() { this->final(true); }
    FinalReceiver(const FinalReceiver&) = default;
    FinalReceiver(FinalReceiver&&) = default;
    virtual ~FinalReceiver() = default;

    FinalReceiver& operator=(const FinalReceiver&) = default;
    FinalReceiver& operator=(FinalReceiver&&) = default;

protected:
    // Receive handlers
    virtual void onReceive(const ::proto::OrderMessage& value) {}
    virtual void onReceive(const ::proto::BalanceMessage& value) {}
    virtual void onReceive(const ::proto::AccountMessage& value) {}

    // Receive message handler
    bool onReceive(size_t type, const void* data, size_t size) override
    {
        switch (type)
        {
            case FBE::proto::OrderMessageFinalModel<ReadBuffer>::fbe_type():
            {
                // Deserialize the value from the FBE stream
                OrderMessageModel.attach(data, size);
                assert(OrderMessageModel.verify() && "proto::OrderMessage validation failed!");
                [[maybe_unused]] size_t deserialized = OrderMessageModel.deserialize(OrderMessageValue);
                assert((deserialized > 0) && "proto::OrderMessage deserialization failed!");

                // Log the value
                if (this->_logging)
                {
                    std::string message = OrderMessageValue.string();
                    this->onReceiveLog(message);
                }

                // Call receive handler with deserialized value
                onReceive(OrderMessageValue);
                return true;
            }
            case FBE::proto::BalanceMessageFinalModel<ReadBuffer>::fbe_type():
            {
                // Deserialize the value from the FBE stream
                BalanceMessageModel.attach(data, size);
                assert(BalanceMessageModel.verify() && "proto::BalanceMessage validation failed!");
                [[maybe_unused]] size_t deserialized = BalanceMessageModel.deserialize(BalanceMessageValue);
                assert((deserialized > 0) && "proto::BalanceMessage deserialization failed!");

                // Log the value
                if (this->_logging)
                {
                    std::string message = BalanceMessageValue.string();
                    this->onReceiveLog(message);
                }

                // Call receive handler with deserialized value
                onReceive(BalanceMessageValue);
                return true;
            }
            case FBE::proto::AccountMessageFinalModel<ReadBuffer>::fbe_type():
            {
                // Deserialize the value from the FBE stream
                AccountMessageModel.attach(data, size);
                assert(AccountMessageModel.verify() && "proto::AccountMessage validation failed!");
                [[maybe_unused]] size_t deserialized = AccountMessageModel.deserialize(AccountMessageValue);
                assert((deserialized > 0) && "proto::AccountMessage deserialization failed!");

                // Log the value
                if (this->_logging)
                {
                    std::string message = AccountMessageValue.string();
                    this->onReceiveLog(message);
                }

                // Call receive handler with deserialized value
                onReceive(AccountMessageValue);
                return true;
            }
            default: break;
        }

        return false;
    }

private:
    // Receiver values accessors
    ::proto::OrderMessage OrderMessageValue;
    ::proto::BalanceMessage BalanceMessageValue;
    ::proto::AccountMessage AccountMessageValue;

    // Receiver models accessors
    FBE::proto::OrderMessageFinalModel<ReadBuffer> OrderMessageModel;
    FBE::proto::BalanceMessageFinalModel<ReadBuffer> BalanceMessageModel;
    FBE::proto::AccountMessageFinalModel<ReadBuffer> AccountMessageModel;
};

} // namespace proto
} // namespace FBE

namespace FBE {
namespace proto {

// Fast Binary Encoding proto final client
template <class TBuffer>
class FinalClient : public virtual FinalSender<TBuffer>, protected virtual FinalReceiver<TBuffer>
{
public:
    FinalClient() = default;
    FinalClient(const FinalClient&) = default;
    FinalClient(FinalClient&&) = default;
    virtual ~FinalClient() = default;

    FinalClient& operator=(const FinalClient&) = default;
    FinalClient& operator=(FinalClient&&) = default;

    // Reset client buffers
    void reset()
    {
        std::scoped_lock locker(this->_lock);
        reset_requests();
    }

    // Watchdog for timeouts
    void watchdog(uint64_t utc)
    {
        std::scoped_lock locker(this->_lock);
        watchdog_requests(utc);
    }

protected:
    std::mutex _lock;
    uint64_t _timestamp{0};

    virtual bool onReceiveResponse(const ::proto::OrderMessage& response) { return false; }
    virtual bool onReceiveResponse(const ::proto::BalanceMessage& response) { return false; }
    virtual bool onReceiveResponse(const ::proto::AccountMessage& response) { return false; }

    virtual bool onReceiveReject(const ::proto::OrderMessage& reject) { return false; }
    virtual bool onReceiveReject(const ::proto::BalanceMessage& reject) { return false; }
    virtual bool onReceiveReject(const ::proto::AccountMessage& reject) { return false; }

    virtual void onReceiveNotify(const ::proto::OrderMessage& notify) {}
    virtual void onReceiveNotify(const ::proto::BalanceMessage& notify) {}
    virtual void onReceiveNotify(const ::proto::AccountMessage& notify) {}

    virtual void onReceive(const ::proto::OrderMessage& value) override { if (!onReceiveResponse(value) && !onReceiveReject(value)) onReceiveNotify(value); }
    virtual void onReceive(const ::proto::BalanceMessage& value) override { if (!onReceiveResponse(value) && !onReceiveReject(value)) onReceiveNotify(value); }
    virtual void onReceive(const ::proto::AccountMessage& value) override { if (!onReceiveResponse(value) && !onReceiveReject(value)) onReceiveNotify(value); }

    // Reset client requests
    virtual void reset_requests()
    {
        Sender<TBuffer>::reset();
        Receiver<TBuffer>::reset();
    }

    // Watchdog client requests for timeouts
    virtual void watchdog_requests(uint64_t utc)
    {
    }
};

} // namespace proto
} // namespace FBE
