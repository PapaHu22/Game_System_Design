#pragma once

class Puzzle {
public:
    virtual void solve() = 0;
    virtual void play() = 0;
    virtual ~Puzzle() {}

    bool isSolved() const { return solved; }
    void setSolved() { solved = true; }

private:
    bool solved = false;
};

class Puzzle1 : public Puzzle {
public:
    void solve() override;
    void play() override;
};

class Puzzle2 : public Puzzle {
public:
    void solve() override;
    void play() override;
};

class Puzzle3 : public Puzzle {
public:
    void solve() override;
    void play() override;
};

class Puzzle4 : public Puzzle {
public:
    void solve() override;
    void play() override;
};

