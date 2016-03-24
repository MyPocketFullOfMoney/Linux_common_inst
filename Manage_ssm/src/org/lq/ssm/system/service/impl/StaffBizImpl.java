package org.lq.ssm.system.service.impl;

import java.util.List;

import javax.annotation.Resource;

import org.lq.ssm.entity.Role;
import org.lq.ssm.entity.Staff;
import org.lq.ssm.system.dao.StaffDao;
import org.lq.ssm.system.service.StaffBiz;
import org.springframework.stereotype.Service;
@Service("staffBizImpl")
public class StaffBizImpl implements StaffBiz {
	/**
	 * 员工实现层
	 */
	@Resource(name="staffDao")
	private StaffDao staffDao;
    /**
     * 查询全部
     */
	@Override
	public List<Staff> findAll() {

		return staffDao.findAll();
	}
	/**
	 * 
	 * 根据ID查询
	 */
	@Override
	public Staff findById(int id) {
		
	  return staffDao.findById(id);
	}
	
	public void setStaffDao(StaffDao staffDao) {
		this.staffDao = staffDao;
	}
	/**
	 * 保存
	 */
	@Override
	public int save(Staff s) {
		Role r=new Role();
		r.setRid(null);
		s.setRoles(r);
		s.setState("在职");
		return staffDao.save(s);
	}
	/**
	 * 根据条件查询
	 */
	@Override
	public List<Staff> likename(String name, String sex) {
		return staffDao.likename(name, sex);
	}
	@Override
	public int update(Staff s) {
		return staffDao.update(s);
	}
	@Override
	public int delete(int id) {
		return staffDao.delete(id);
	}
	@Override
	public int updateRole(Staff s) {
		return staffDao.updateRole(s);
	}
	@Override
	public Staff findByname(String name) {
		return staffDao.findByname(name);
	}
	@Override
	public List<Staff> findTeacher() {
		return staffDao.findTeacher();
	}
	




}
