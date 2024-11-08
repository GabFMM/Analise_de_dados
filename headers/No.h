#pragma once

#include "Informacao.h"

struct No {
	No* proximo;
	No* anterior;
	Informacao info;
};