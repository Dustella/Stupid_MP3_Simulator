#include "favMusicList.h"
#include <vector>

LikeMusicList::LikeMusicList(vector<music> MList)
{
	for (auto e : MList)
	{
		if (e.isLiked() == false)
			e.setLiked();
		MList.push_back(e);
	}
	updateLength();
}


