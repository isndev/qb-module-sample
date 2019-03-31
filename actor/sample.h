//
// Created by isnDev on 3/11/2019.
//

#include <qb/actor.h>
#include "../event/input.h"
#include "../event/all.h"

#ifndef QB_MODULE_SAMPLE_ACTOR_SAMPLE_H
#define QB_MODULE_SAMPLE_ACTOR_SAMPLE_H

namespace qbm {
    namespace sample {
        namespace actor {
            class Sample : public qb::Actor {
            public:
                Sample() = default;
                virtual bool onInit() override final {
                    registerEvent<event::input>(*this);
                    LOG_INFO("Loaded Module Sample Actor");
                    return true;
                }

                void on(event::input const &event) {
                    push<event::output>(event.getSource());
                }
            };
        }
    }
}

#endif //QB_MODULE_SAMPLE_ACTOR_SAMPLE_H
