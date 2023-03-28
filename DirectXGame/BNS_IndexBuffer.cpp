#include "BNS_IndexBuffer.h"
#include "BNS_RenderSystem.h"
#include <exception>

BNS_IndexBuffer::BNS_IndexBuffer(void* list_indices, UINT size_list, BNS_RenderSystem* system) : m_system(system), m_buffer(0)
{
	// describe a buffer resource
	D3D11_BUFFER_DESC buff_desc = {};
	// checks if our buffer is accessible by CPU and GPU; default means it could be written by both CPU and GPU
	buff_desc.Usage = D3D11_USAGE_DEFAULT;
	buff_desc.ByteWidth = 4 * size_list;
	// we want our buffer to be bind as a index buffer
	buff_desc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	buff_desc.CPUAccessFlags = 0;
	buff_desc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA init_data = {};
	// passing the list of references of the vertices to the 'pSysMemory'
	init_data.pSysMem = list_indices;

	m_size_list = size_list;

	if (FAILED(m_system->m_d3d_device->CreateBuffer(&buff_desc, &init_data, &m_buffer)))
	{
		throw std::exception("BNS_IndexBuffer not created successfully");
	}
}

UINT BNS_IndexBuffer::getSizeIndexList()
{
	return this->m_size_list;
}

BNS_IndexBuffer::~BNS_IndexBuffer()
{
	m_buffer->Release();
}
