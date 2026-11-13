#include "game_view.hpp"

#include <cmath>

#include <QPainter>

using biv::GameView;

GameView::GameView(QWidget* parent) : QWidget(parent) {
	setFixedSize(
		static_cast<int>(MAP_WIDTH * UNIT),
		static_cast<int>(MAP_HEIGHT * UNIT)
	);
	setAttribute(Qt::WA_OpaquePaintEvent);

	loadSprites();
	buildBackground();
}

void GameView::setFrame(const SceneFrame& new_frame) {
	frame = new_frame;
	update();
}

QSize GameView::sizeHint() const {
	return size();
}

void GameView::paintEvent(QPaintEvent*) {
	QPainter painter(this);
	painter.drawPixmap(0, 0, background);

	for (const ObjectFrame& object : frame.objects) {
		drawObject(painter, object);
	}
}

void GameView::loadSprites() {
	auto add = [this](char type, const char* file_name) {
		QString path = QStringLiteral(":/sprites/");
		path += file_name;
		sprites.insert(type, QPixmap(path));
	};

	add('@', "mario.png");
	add('e', "goomba.png");
	add('b', "fly_enemy.png");
	add('j', "jump_enemy.png");
	add('$', "coin.png");
	add('#', "brick.png");
	add('?', "mystery_block.png");
	add('-', "empty_block.png");
	add('=', "moving_platform.png");
}

void GameView::buildBackground() {
	background = QPixmap(QStringLiteral(":/sprites/background.png"));
	if (background.size() != size()) {
		background = background.scaled(
			size(),
			Qt::IgnoreAspectRatio,
			Qt::SmoothTransformation
		);
	}
}

void GameView::drawObject(QPainter& painter, const ObjectFrame& object) {
	auto it = sprites.constFind(object.type);
	if (it == sprites.constEnd() || it->isNull()) {
		return;
	}

	switch (object.type) {
		case '#':
		case '?':
		case '-':
		case '=':
			drawTiledSprite(painter, *it, object);
			break;
		default:
			painter.drawPixmap(
				QPointF(object.x * UNIT, object.y * UNIT),
				*it
			);
			break;
	}
}

void GameView::drawTiledSprite(
	QPainter& painter,
	const QPixmap& sprite,
	const ObjectFrame& object
) {
	if (object.width <= 0 || object.height <= 0) {
		return;
	}

	const float tile_width = sprite.width() / UNIT;
	const float tile_height = sprite.height() / UNIT;
	if (tile_width <= 0 || tile_height <= 0) {
		return;
	}

	painter.save();
	painter.setClipRect(QRectF(
		object.x * UNIT,
		object.y * UNIT,
		object.width * UNIT,
		object.height * UNIT
	));

	const int columns = static_cast<int>(std::ceil(object.width / tile_width));
	const int rows = static_cast<int>(std::ceil(object.height / tile_height));

	for (int row = 0; row < rows; row++) {
		for (int column = 0; column < columns; column++) {
			painter.drawPixmap(
				QPointF(
					(object.x + column * tile_width) * UNIT,
					(object.y + row * tile_height) * UNIT
				),
				sprite
			);
		}
	}

	painter.restore();
}
