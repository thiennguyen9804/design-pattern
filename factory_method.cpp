//
// Created by Welcome on 12/17/2024.
//
#include <iostream>
#include <string>

using namespace std;


class Button {
public:
    virtual ~Button() = default;
    virtual void onClick() const = 0;
    virtual void render() const = 0;
};

class WindowsButton final : public Button {
    void onClick() const override {
        cout << "Bind a native OS click event" << endl;
    }

    void render() const override {
        cout << "Render a button in Windows style" << endl;
    }
};

class HtmlButton final : public Button {
    void onClick() const override {
        cout << "Bind a web browser click event" << endl;
    }

    void render() const override {
        cout << " Return an HTML representation of a button" << endl;
    }
};

class Dialog {
public:
    virtual ~Dialog() = default;
    [[nodiscard]] virtual Button* createButton() const = 0;

    void render() const {
        const Button* button = this->createButton();
        button->onClick();
        button->render();
    }
};

class WindowsDialog final : public Dialog {
    [[nodiscard]] Button* createButton() const override {
        return new WindowsButton;
    }
};

class HtmlDialog final : public Dialog {
    [[nodiscard]] Button* createButton() const override {
        return new HtmlButton;
    }
};

class Application {
    Dialog*dialog = nullptr;
public:
    Application() {
        if (const string os = "Windows"; os == "Windows") {
            dialog = new WindowsDialog;
        } else if (os == "Html") {
            dialog = new HtmlDialog;
        } else {
            throw runtime_error("Unknown OS");
        }

        dialog->render();
    }
};

void run() {
    new Application();
}