#include "Tool.h"
#include "Fazendinha.h"
#include "Ground.h"

Tool::Tool() {
	tileset = new TileSet("Resources/regador.png", 16, 32, 5, 5);
	animation = new Animation(tileset, 0.2, true);


	uint front[2] = { 0, 1 };
	uint side[2] = { 2, 3 };

	animation->Add(TOOLFRONT, front, 2);
	animation->Add(TOOLSIDE, side, 2);

	BBox(new Rect(-4, 16, 4, 21));

	Scale(2.0);

	// fazer um if pra ver se é um regador ou um arador
	// configuração do gerador de partículas
	Generator emitter;
	emitter.imgFile = "Resources/Spark.png";    // arquivo de imagem
	emitter.angle = 270.0f;                     // ângulo base do emissor
	emitter.spread = 25;                        // espalhamento em graus
	emitter.lifetime = 0.5f;                    // tempo de vida em segundos
	emitter.frequency = 0.030f;                 // tempo entre geração de novas partículas
	emitter.percentToDim = 0.6f;                // desaparece após 60% da vida
	emitter.minSpeed = 50.0f;                   // velocidade mínima das partículas
	emitter.maxSpeed = 50.0f;                  // velocidade máxima das partículas
	emitter.color.r = 0.0f;                     // componente Red da partícula 
	emitter.color.g = 0.0f;                     // componente Green da partícula 
	emitter.color.b = 3.5f;                     // componente Blue da partícula 
	emitter.color.a = 0.7f;                     // transparência da partícula

	// cria sistema de partículas
	agua = new Particles(emitter);

	type = REGADOR;

}

Tool::~Tool() {
	delete tileset;
	delete animation;
	delete agua;
}

void Tool::Update() {

	if (animation->Frame() == 1 || animation->Frame() == 3) {
		if (timer.Elapsed(2.0f)) {
			animation->NextFrame();
			Fazendinha::scene->Delete();
		}
	}
	else {
		animation->NextFrame();
		timer.Start();
	}

	if (agua != nullptr) {
		agua->Generate(x + 1, y + 12);
		agua->Update(gameTime);
	}
	

	animation->Select(state);

}

void Tool::Draw() {
	animation->Draw(x, y, z, scale);
	if (agua != nullptr) {
		agua->Draw(Layer::LOWER, 1.0f);
	}
}


void Tool::OnCollision(Object* obj) {
	if (obj->Type() == GROUND) {
		Ground* ground = dynamic_cast<Ground*>(obj);
		if (!ground->isMolhado) {
			ground->isMolhado = true;
		}
	}
}
