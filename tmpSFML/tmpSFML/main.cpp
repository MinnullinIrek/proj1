
#include <SFML/Graphics.hpp>
using namespace sf;

#include "hero.h"
#include "map.h"
#include "Game.h"

//const int HEIGHT_MAP = 25;//размер карты высота
//const int WIDTH_MAP = 40;//размер карты ширина 
//sf::String TileMap[HEIGHT_MAP] = {
//"0000000000000000000000000000000000000000",
//"0                                      0",
//"0   s                                  0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0                                      0",
//"0000000000000000000000000000000000000000",
//};


int main() {
    Game& game = Game::instance();
    game.Initialize(400, 400);



    while (game.IsRunning())
    {

        game.Update();
    }

    return 0;
}

int main4() {

    RenderWindow window(VideoMode(400, 400), L"Новый проект", Style::Default);

    window.setVerticalSyncEnabled(true);

    CircleShape shape(100.f, 3);
    shape.setPosition(100, 100);
    shape.setFillColor(Color::Magenta);

    Image heroImage;
    heroImage.loadFromFile("images/hero.png");

    Texture heroTexture;
    heroTexture.loadFromImage(heroImage);

    Sprite heroSprite;
    heroSprite.setTexture(heroTexture);
    heroSprite.setTextureRect(IntRect(96, 192, -96, 96));
    heroSprite.setPosition(50, 25);

    Clock clock;

    float currentFrame = 0;

    Player p("hero.png", 256, 256, 96, 96);

    Image map_image;//объект изображения для карты
    map_image.loadFromFile("images/map.png");//загружаем файл для карты
    Texture map;//текстура карты
    map.loadFromImage(map_image);//заряжаем текстуру картинкой
    Sprite s_map;//создаём спрайт для карты
    s_map.setTexture(map);//заливаем текстуру спрайтом

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;
        float d = 0.1 * time;
        
        if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
            p.dir = 1; p.speed = 0.1;//dir =1 - направление вверх, speed =0.1 - скорость движения. Заметьте - время мы уже здесь ни на что не умножаем и нигде не используем каждый раз
            currentFrame += 0.005 * time;
            if (currentFrame > 3) currentFrame -= 3;
            p.sprite.setTextureRect(IntRect(96 * int(currentFrame), 96, 96, 96)); //через объект p класса player меняем спрайт, делая анимацию (используя оператор точку)
        }

        if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
            p.dir = 0; p.speed = 0.1;//направление вправо, см выше
            currentFrame += 0.005 * time;
            if (currentFrame > 3) currentFrame -= 3;
            p.sprite.setTextureRect(IntRect(96 * int(currentFrame), 192, 96, 96)); //через объект p класса player меняем спрайт, делая анимацию (используя оператор точку)
        }

        if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
            p.dir = 3; p.speed = 0.1;//направление вниз, см выше
            currentFrame += 0.005 * time;
            if (currentFrame > 3) currentFrame -= 3;
            p.sprite.setTextureRect(IntRect(96 * int(currentFrame), 288, 96, 96)); //через объект p класса player меняем спрайт, делая анимацию (используя оператор точку)

        }

        if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) { //если нажата клавиша стрелка влево или англ буква А
            p.dir = 2; p.speed = 0.1;//направление вверх, см выше
            currentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
            if (currentFrame > 3) currentFrame -= 3; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
            p.sprite.setTextureRect(IntRect(96 * int(currentFrame), 0, 96, 96)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96

        }

        p.update(time);
        window.clear(Color::Blue);
        //window.draw(shape);
        for (int i = 0; i < HEIGHT_MAP; i++)
            for (int j = 0; j < WIDTH_MAP; j++)
            {
                if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
                if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));//если встретили символ s, то рисуем 2й квадратик
                if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик


                s_map.setPosition(j * 32, i * 32);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат

                window.draw(s_map);//рисуем квадратики на экран
            }
        window.draw(p.sprite);
        window.display();
    }

	return 0;
}

