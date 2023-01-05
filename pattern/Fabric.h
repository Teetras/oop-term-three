#pragma once
#include"Document.h"
#include"Documents.h"


class DocumentFabric {
public:
	Document* makeDocument(Documents type) {
		switch (type)
		{
		case Descriptionn: return new Description;
		case Formatt: return new Format;
		default: return nullptr;
		}
	}

	Document* makeDocument(DocumentSpec* type) {
		switch (type->docType())
		{
		case Descriptionn: return new Description(static_cast<DescriptionSpec*>(type));
		case Formatt: return new Format(static_cast<FormatSpec*>(type));
		default: return nullptr;
		}
	}
};
