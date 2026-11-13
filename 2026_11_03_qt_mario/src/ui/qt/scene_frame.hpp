#pragma once

#include <vector>

#include <QMetaType>

namespace biv {
	struct ObjectFrame {
		float x;
		float y;
		float width;
		float height;
		char type;
	};

	struct SceneFrame {
		std::vector<ObjectFrame> objects;
	};
}

Q_DECLARE_METATYPE(biv::SceneFrame)
