#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;
using namespace std;
class tilemap : public Drawable, public Transformable {
public:
    bool load(const string& tileset, Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);

private:
    virtual void draw(RenderTarget& target, RenderStates states) const override;

    VertexArray m_vertices;
    Texture m_tileset;
};
