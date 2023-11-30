#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>
#include <imgui-SFML.h>
#include <imgui.h>

void* _ = 0;
#define discard _ = (void*)

void ProcessEvents(sf::RenderWindow &window) {
  sf::Event event;
  while (window.pollEvent(event)) {
    ImGui::SFML::ProcessEvent(window, event);

    if (event.type == sf::Event::Closed) {
      window.close();
    }
  }
}

int main() {
  sf::RenderWindow window(sf::VideoMode(640, 480), "ImGui + SFML = <3");
  window.setFramerateLimit(60);

  discard ImGui::SFML::Init(window);

  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  sf::Clock deltaClock;
  sf::Time clickTimer;
  while (window.isOpen()) {
    ProcessEvents(window);
    const sf::Time deltaTime = deltaClock.restart();
    ImGui::SFML::Update(window, deltaTime);

    ImGui::ShowDemoWindow();

    ImGui::Begin("Hello, world!");
    auto clicked = ImGui::Button("Look at this pretty button");
    if (clicked) {
      clickTimer = sf::seconds(5);
    }
    if (clickTimer > sf::Time::Zero) {
      ImGui::Text("You clicked it! %.3lf", clickTimer.asSeconds());
      clickTimer -= deltaTime;
    } else {
      clickTimer = sf::Time::Zero;
    }

    ImGui::End();

    window.clear();
    window.draw(shape);
    ImGui::SFML::Render(window);
    window.display();
  }

  ImGui::SFML::Shutdown();
}