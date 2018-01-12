#include <iostream>
#include <vector>

class IThingy;
struct PurpleThingy;
struct LittleThingy;

class IThingyInteractor;

// Every Thingy is gonna have an identical 
// acceptInteraction function. Unfortunate, I know.
#define ACCEPTS void acceptInteraction(IThingyInteractor *bla) \
     { bla->interact(this); }

struct IThingy { 
    virtual void acceptInteraction(IThingyInteractor *bla) = 0;
};

struct IThingyInteractor {
    // IMPORTANT BIT: we specify the dispatch over all
    // kinds of thingies (that we care about) here
    virtual void interact(PurpleThingy *thingy) = 0;
    virtual void interact(LittleThingy *thingy) = 0;
};

struct PurpleThingy : public IThingy { 
    ACCEPTS;
};
struct LittleThingy : public IThingy { 
    ACCEPTS;
};
struct ProblemThingy : public IThingy {
    void acceptInteraction(IThingyInteractor *bla) { 
        std::cerr << "whatever\n"; 
    }
};

struct SayerOfObviousThingAboutThingy : IThingyInteractor {
    // I'm mean, it is!
    void interact(PurpleThingy *thingy) { std::cout << "This is purple\n"; }
    void interact(LittleThingy *thingy) { std::cout << "This is little\n"; }
};

struct ThingTreasurer : IThingyInteractor {
    // Isn't that what that word means
    void interact(PurpleThingy *thingy) { std::cout << "I cherish this purple thingy\n"; }
    void interact(LittleThingy *thingy) { std::cout << "I cherish this little thingy\n"; }
};

int main() {
    PurpleThingy purp;
    LittleThingy lil;
    IThingy *thingies[] = { &purp, &lil };

    SayerOfObviousThingAboutThingy sayer;
    ThingTreasurer treasurer;
    IThingyInteractor *interactors[] = { &sayer, &treasurer };

    for (auto thingy_p : thingies) {
        for (auto interactor_p : interactors) {
            thingy_p->acceptInteraction(interactor_p);
        }
    }
    return 0;
}
