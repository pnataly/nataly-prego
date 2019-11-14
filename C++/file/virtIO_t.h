#ifndef __VIRTIO_T_H__
#define __VIRTIO_T_H__

class virtIO_t
{
	public:
		virtIO_t();
		virtIO_t(const string& _pathname, const string& _mode);
		
		typedef enum Status_e {ok_e, cant_open_file_e, bad_access_e, writeErr_e, readErr_e}Status_e;
		const Status_e GetFileStatus() const {return m_status;}
		void SetFileStatus(Status_e _stat) {m_status = _stat;}
		
	private:
		void* m_buf;
		char& m_flag; //read/write.
		Status_e m_status;
};



#endif /*__VIRTIO_T_H__*/
