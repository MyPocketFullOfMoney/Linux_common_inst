package org.lq.ssm.student.service.impl;

import java.util.List;

import javax.annotation.Resource;

import org.lq.ssm.entity.Student;
import org.lq.ssm.student.dao.StudentDao;
import org.lq.ssm.student.service.StudentBiz;
import org.springframework.stereotype.Service;

@Service("studentBizImpl")
public class StudentBizImpl implements StudentBiz {
	
	@Resource(name="studentDao")
	private StudentDao studentDao;
	
	@Override
	public List<Student> findAll() {
		return studentDao.findAll();
	}

	@Override
	public boolean delete(int id) {
		return studentDao.delete(id)>0;
	}

	@Override
	public Student findById(int id) {
		return studentDao.findById(id);
	}

	@Override
	public List<Student> findByName(String name) {
		return studentDao.findByName(name);
	}

	@Override
	public boolean save(Student s) {
		return studentDao.save(s)>0;
	}

	@Override
	public boolean update(Student s) {
		return studentDao.update(s)>0;
	}

	public void setStudentDao(StudentDao studentDao) {
		this.studentDao = studentDao;
	}

	@Override
	public List<Student> getstubypay(String ispay) {
		return studentDao.getstubypay(ispay);
	}
//---------------------------------------------------
	@Override
	public List<Student> findStudentPool() {
		
		return studentDao.findStudentPool();
	}

	@Override
	public boolean delete1(int id) {
		
		return studentDao.delete1(id)>0;
	}

	@Override
	public boolean save1(Student s) {
		
		return studentDao.save1(s)>0;
	}

	@Override
	public boolean updateState(int id) {
		
		return studentDao.updateState(id)>0;
	}

	@Override
	public boolean updateStudent(Student s) {
		
		return studentDao.updateStudent(s)>0;
	}

	@Override
	public List<Student> findByCon(String sname, Integer state) {
		return studentDao.findByCon(sname, state);
	}

}
