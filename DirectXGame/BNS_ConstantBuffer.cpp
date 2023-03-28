#include "BNS_ConstantBuffer.h"
#include "BNS_RenderSystem.h"
#include "BNS_DeviceContext.h"
#include <exception>

BNS_ConstantBuffer::BNS_ConstantBuffer(void* buffer, UINT size_buffer, BNS_RenderSystem* system) : m_system(system)
{
	// describe a buffer resource
	D3D11_BUFFER_DESC buff_desc = {};
	// checks if our buffer is accessible by CPU and GPU; default means it could be written by both CPU and GPU
	buff_desc.Usage = D3D11_USAGE_DEFAULT;
	buff_desc.ByteWidth = size_buffer;
	// we want our buffer to be bind as a constant buffer
	buff_desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	buff_desc.CPUAccessFlags = 0;
	buff_desc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA init_data = {};
	// passing the buffer reference to the 'pSysMemory'
	init_data.pSysMem = buffer;

	if (FAILED(m_system->m_d3d_device->CreateBuffer(&buff_desc, &init_data, &m_buffer)))
	{
		throw std::exception("BNS_ConstantBuffer not created successfully");
	}
}


void BNS_ConstantBuffer::update(DeviceContextPtr context, void* buffer)
{
	context->m_device_context->UpdateSubresource(this->m_buffer, NULL, NULL, buffer, NULL, NULL);
}

BNS_ConstantBuffer::~BNS_ConstantBuffer()
{
	if (m_buffer)m_buffer->Release();
}