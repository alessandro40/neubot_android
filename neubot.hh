//
// LibNeubot interface - Public domain.
// WARNING: Autogenerated file - do not edit!
//

#include <stdlib.h>
#include <new>

namespace Neubot {

#include <neubot.h>

    class EchoServer;
    class Pollable;
    class Poller;

    class EchoServer {
        struct NeubotEchoServer *_context;

      public:

// Swig doesn't understand the cast operator
#ifndef SWIG
        operator struct NeubotEchoServer *(void) {
            return (this->_context);
        }
#endif

        EchoServer(Poller *poller, int use_ipv6, const char *address,
          const char *port) {
            this->_context = NeubotEchoServer_construct(
              (struct NeubotPoller *) poller, use_ipv6, address, port);
            if (this->_context == NULL)
                throw new std::bad_alloc();
        };

    };

    class Pollable {
        struct NeubotPollable *_context;

        static void handle_read__(void *opaque) {
            Pollable *self = (Pollable *) opaque;
            self->handle_read();
        };

        static void handle_write__(void *opaque) {
            Pollable *self = (Pollable *) opaque;
            self->handle_write();
        };

        static void handle_close__(void *opaque) {
            Pollable *self = (Pollable *) opaque;
            self->handle_close();
        };

      public:

// Swig doesn't understand the cast operator
#ifndef SWIG
        operator struct NeubotPollable *(void) {
            return (this->_context);
        }
#endif

        virtual void handle_read(void) = 0;

        virtual void handle_write(void) = 0;

        virtual void handle_close(void) = 0;

        Pollable(Poller *poller) {
            this->_context = NeubotPollable_construct(
              (struct NeubotPoller *) poller, this->handle_read__,
              this->handle_write__, this->handle_close__, this);
            if (this->_context == NULL)
                throw new std::bad_alloc();
        };

        int attach(long long filenum) {
            return (NeubotPollable_attach(this->_context, filenum));
        };

        void detach(void) {
            NeubotPollable_detach(this->_context);
        };

        long long fileno(void) {
            return (NeubotPollable_fileno(this->_context));
        };

        int set_readable(void) {
            return (NeubotPollable_set_readable(this->_context));
        };

        int unset_readable(void) {
            return (NeubotPollable_unset_readable(this->_context));
        };

        int set_writable(void) {
            return (NeubotPollable_set_writable(this->_context));
        };

        int unset_writable(void) {
            return (NeubotPollable_unset_writable(this->_context));
        };

        void set_timeout(double delta) {
            NeubotPollable_set_timeout(this->_context, delta);
        };

        void clear_timeout(void) {
            NeubotPollable_clear_timeout(this->_context);
        };

        virtual ~Pollable(void) {
            NeubotPollable_close(this->_context);
        };

    };

    class Poller {
        struct NeubotPoller *_context;

      public:

// Swig doesn't understand the cast operator
#ifndef SWIG
        operator struct NeubotPoller *(void) {
            return (this->_context);
        }
#endif

        Poller(void) {
            this->_context = NeubotPoller_construct();
            if (this->_context == NULL)
                throw new std::bad_alloc();
        };


// We use another strategy to generate closure code
#ifndef SWIG
        int sched(double delta, neubot_hook_vo callback, void *opaque) {
            return (NeubotPoller_sched(this->_context, delta, callback, opaque));
        };
#endif


// We use another strategy to generate closure code
#ifndef SWIG
        int defer_read(long long fileno, neubot_hook_vo handle_ok,
          neubot_hook_vo handle_timeout, void *opaque, double timeout) {
            return (NeubotPoller_defer_read(this->_context, fileno, handle_ok,
              handle_timeout, opaque, timeout));
        };
#endif


// We use another strategy to generate closure code
#ifndef SWIG
        int defer_write(long long fileno, neubot_hook_vo handle_ok,
          neubot_hook_vo handle_timeout, void *opaque, double timeout) {
            return (NeubotPoller_defer_write(this->_context, fileno, handle_ok,
              handle_timeout, opaque, timeout));
        };
#endif


// We use another strategy to generate closure code
#ifndef SWIG
        int resolve(int use_ipv6, const char *name,
          neubot_hook_vos callback, void *opaque) {
            return (NeubotPoller_resolve(this->_context, use_ipv6, name,
              callback, opaque));
        };
#endif

        void loop(void) {
            NeubotPoller_loop(this->_context);
        };

        void break_loop(void) {
            NeubotPoller_break_loop(this->_context);
        };

    };

};
