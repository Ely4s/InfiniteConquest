//
// Created by Elyas EL IDRISSI on 18/03/2021.
//

#ifndef INFINITECONQUEST_INSTANCEOF_H
#define INFINITECONQUEST_INSTANCEOF_H

template<typename Base, typename E>
inline bool instanceof(const E *ptr) {
	return dynamic_cast<const Base*>(ptr) != nullptr;
}

#endif //INFINITECONQUEST_INSTANCEOF_H
