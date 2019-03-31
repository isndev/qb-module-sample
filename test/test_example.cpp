#include <gtest/gtest.h>
#include <qb/main.h>
#include "../actor/sample.h"
#include "../service/sample.h"

class TestActor : public qb::Actor {
    qb::ActorId _to;
public:
    explicit TestActor(qb::ActorId const to)
            : _to(to ? to : getServiceId<qbm::sample::service::Tag>(0))
    {}

    virtual bool onInit() override final {
        registerEvent<qbm::sample::event::output>(*this);
        push<qbm::sample::event::input>(_to);
        return true;
    }

    void on(qbm::sample::event::output const &event) {
        push<qb::KillEvent>(event.getSource());
        kill();
    }
};

TEST(Example, TestSampleActorOutput) {
    qb::Main main({0});

    auto id = main.addActor<qbm::sample::actor::Sample>(0);
    main.addActor<TestActor>(0, id);

    main.start();
    main.join();
    EXPECT_FALSE(main.hasError());
}

TEST(Example, TestSampleServiceOutput) {
    qb::Main main({0});

    auto id = main.addActor<qbm::sample::service::Sample>(0);
    main.addActor<TestActor>(0, id);

    main.start();
    main.join();
    EXPECT_FALSE(main.hasError());
}